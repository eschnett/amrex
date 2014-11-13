"""PyBoxLib fab class."""

__all__ = [ 'fab' ]

import fcboxlib
import numpy as np

class fab():
  """FAB.

  Here we assume that a fab is attached to a multifab.

  DIM:    Dimension
  BX:     The Box in index space for which this FAB is defined
  IBX:    The index range of the valid data for the FAB
  PBX:    The physical box for the FAB
  NC:     Number of components
  NG:     Number of ghost cells

  When a FAB is created IBX = BX, unless it is nodal, in which case
  IBX = grow(BX, FACE=hi, 1 (in the nodal directions).
  PBX = grow(IBX, NG)

  For parallel systems the BX, IBX, PBX, etc are all defined, but the
  underlying pointer will not be allocated.

  All FABS are 'Four' dimensional, conventially, (NX,NY,NZ,NC) in size.
  NY = 1, NZ = 1, when DIM =1, NZ = 1, when DIM = 2.

  """

  def __init__(self, mfab, nbox, logical=False, squeeze=False):
    if logical:
      a = fcboxlib.lmultifab_as_numpy(mfab.cptr, nbox)
    else:
      a = fcboxlib.multifab_as_numpy(mfab.cptr, nbox)
    if squeeze:
      self.array = a.squeeze()
    else:
      shp = a.shape[:mfab.dim] + (a.shape[3],)
      self.array = a.reshape(shp)

  @property
  def shape(self):
    return self.array.shape

  @property
  def size(self):
    return self.array.size


#   def bxrange(self, dim):
#     """Return an iterator to cycle over the global indicies for the
#     given dimension.

#     Essentially this returns ``range(lo(dim), hi(dim)+1)``.
#     """

#     return range(self.bx[0][dim-1], self.bx[1][dim-1]+1)


#   def __getitem__(self, key):
#     lbound = list(self.pbx[0])
#     if self.nc > 1:
#       lbound.append(0)

#     key = adjust_indexes(lbound, key)

#     return self.array[key]


#   def __setitem__(self, key, value):
#     lbound = list(self.pbx[0])
#     if self.nc > 1:
#       lbound.append(0)

#     key = adjust_indexes(lbound, key)

#     self.array[key] = value


# # adapted from petsc4py
# def adjust_indexes(lbounds, index):
#    if not isinstance(index, tuple):
#        return adjust_index(lounds[0], index)

#    index = list(index)
#    for i, start in enumerate(lbounds):
#        index[i] = adjust_index(start, index[i])
#    index = tuple(index)

#    return index


# # adapted from petsc4py
# def adjust_index(lbound, index):

#   if index is None:
#       return index

#   if index is Ellipsis:
#       return index

#   if isinstance(index, slice):
#       start = index.start
#       stop  = index.stop
#       step  = index.step
#       if start is not None: start -= lbound
#       if stop  is not None: stop  -= lbound
#       return slice(start, stop, step)

#   try:
#       return index - lbound

#   except TypeError:
#       return index
