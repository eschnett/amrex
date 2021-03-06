#ifndef AMREX_ML_NODE_LAP_F_H_
#define AMREX_ML_NODE_LAP_F_H_

#include <AMReX_BLFort.H>

#ifdef __cplusplus
extern "C" {
#endif

    void amrex_mlndlap_copy_fine_node (const int* lo, const int* hi,
                                       amrex_real* d, const int* dlo, const int* dhi,
                                       const amrex_real* s, const int* slo, const int* shi,
                                       const int* msk, const int* mlo, const int* mhi);

    void amrex_mlndlap_solution_residual (const int* lo, const int* hi,
                                          amrex_real* res, const int* rlo, const int* rhi,
                                          const amrex_real* b, const int* blo, const int* bhi,
                                          const int* msk, const int* mlo, const int* mhi,
					  const int* nc);

#if (AMREX_SPACEDIM == 2)
    void amrex_mlndlap_set_rz (const int* rz);
#endif

    int amrex_mlndlap_any_fine_sync_cells (const int* lo, const int* hi,
                                           const int* msk, const int* mlo, const int* mhi,
                                           const int* fine_flag);

    void amrex_mlndlap_fillbc_cc (amrex_real* sigma, const int* slo, const int* shi,
                                  const int* dlo, const int* dhi,
                                  const void* bclo, const void* bchi);

    void amrex_mlndlap_fillbc_cc_i (int* sigma, const int* slo, const int* shi,
                                    const int* dlo, const int* dhi,
                                    const void* bclo, const void* bchi);

    void amrex_mlndlap_applybc (amrex_real* phi, const int* hlo, const int* hhi,
                                const int* dlo, const int* dhi,
                                const void* bclo, const void* bchi);

    void amrex_mlndlap_restriction (const int* lo, const int* hi,
                                    amrex_real* crse, const int* clo, const int* chi,
                                    const amrex_real* fine, const int* flo, const int* fhi,
                                    const int* dmsk, const int* dmlo, const int* dmhi);

    void amrex_mlndlap_interpolation_ha (const int* clo, const int* chi,
                                      amrex_real* fine, const int* fflo, const int* ffhi,
                                      const amrex_real* crse, const int* cflo, const int* cfhi,
                                      const amrex_real* sx, const int* sxlo, const int* sxhi,
#if (AMREX_SPACEDIM >= 2)
                                      const amrex_real* sy, const int* sylo, const int* syhi,
#if (AMREX_SPACEDIM == 3)
                                      const amrex_real* sz, const int* szlo, const int* szhi,
#endif
#endif
                                      const int* dmsk, const int* dmlo, const int* dmhi,
                                      const int* domlo, const int* domhi,
                                      const void* bclo, const void* bchi);


    void amrex_mlndlap_interpolation_aa (const int* clo, const int* chi,
                                      amrex_real* fine, const int* fflo, const int* ffhi,
                                      const amrex_real* crse, const int* cflo, const int* cfhi,
                                      const amrex_real* sig, const int* siglo, const int* sighi,
                                      const int* dmsk, const int* dmlo, const int* dmhi,
                                      const int* domlo, const int* domhi,
                                      const void* bclo, const void* bchi);

    void amrex_mlndlap_divu_fine_contrib (const int* clo, const int* chi,
                                          const int* cgrid_lo, const int* cgrid_hi,
                                          amrex_real* rhs, const int* rlo, const int* rhi,
                                          const amrex_real* vel, const int* vlo, const int* vhi,
                                          amrex_real* frh, const int* flo, const int* fhi,
                                          const int* dmsk, const int* mlo, const int* mhi,
                                          const amrex_real* dxinv);

    void amrex_mlndlap_divu_cf_contrib (const int* lo, const int* hi,
                                        amrex_real* rhs, const int* rlo, const int* rhi,
                                        const amrex_real* vel, const int* vlo, const int* vhi,
                                        const int* dmsk, const int* dmlo, const int* dmhi,
                                        const int* ndmsk, const int* ndmlo, const int* ndmhi,
                                        const int* ccmsk, const int* ccmlo, const int* ccmhi,
                                        const amrex_real* cc, const int* clo, const int* chi,
                                        const amrex_real* dxinv, const int* ndlo, const int* ndhi,
                                        const void* bclo, const void* bchi);

    void amrex_mlndlap_crse_resid (const int* lo, const int* hi,
                                   amrex_real* resid, const int* rslo, const int* rshi,
                                   const amrex_real* rhs, const int* rhlo, const int* rhhi,
                                   const int* msk, const int* mlo, const int* mhi,
                                   const int* ndlo, const int* ndhi,
                                   const void* bclo, const void* bchi);

    void amrex_mlndlap_res_fine_contrib (const int* clo, const int* chi,
                                         const int* cgrid_lo, const int* cgrid_hi,
                                         amrex_real* fc, const int* flo, const int* fhi,
                                         const amrex_real* phi, const int* phlo, const int* phhi,
                                         const amrex_real* sig, const int* slo, const int* shi,
                                         amrex_real* Ax, const int* alo, const int* ahi,
                                         const int* dmsk, const int* dmlo, const int* dmhi,
                                         const amrex_real* dxinv);

    void amrex_mlndlap_res_cf_contrib (const int* lo, const int* hi,
                                       amrex_real* res, const int* rlo, const int* rhi,
                                       const amrex_real* phi, const int* phlo, const int* phhi,
                                       const amrex_real* rhs, const int* rhlo, const int* rhhi,
                                       const amrex_real* sig, const int* slo, const int* shi,
                                       const int* dmsk, const int* mlo, const int* mhi,
                                       const int* ndmsk, const int* ndmlo, const int* ndmhi,
                                       const int* ccmsk, const int* ccmlo, const int* ccmhi,
                                       const amrex_real* cc, const int* clo, const int* chi,
                                       const amrex_real* dxinv, const int* ndlo, const int* ndhi,
                                       const void* bclo, const void* bchi);

    void amrex_mlndlap_zero_fine (const int* lo, const int* hi,
                                  amrex_real* phi, const int* philo, const int* phihi,
                                  const int* msk, const int* mlo, const int* mhi,
                                  const int* fine_flag);


    void amrex_mlndlap_rhcc_fine_contrib (const int* clo, const int* chi,
                                          const int* cgrid_lo, const int* cgrid_hi,
                                          amrex_real* rhs, const int* rlo, const int* rhi,
                                          const amrex_real* cc, const int* cclo, const int* cchi,
                                          const int* dmsk, const int* mlo, const int* mhi);

    void amrex_mlndlap_rhcc_crse_contrib (const int* lo, const int* hi,
                                          amrex_real* crhs, const int* rlo, const int* rhi,
                                          const amrex_real* cc, const int* cclo, const int* cchi,
                                          const int* dmsk, const int* dmlo, const int* dmhi,
                                          const int* ndmsk, const int* ndmlo, const int* ndmhi,
                                          const int* ccmsk, const int* ccmlo, const int* ccmhi);

    // stencils
    
    void amrex_mlndlap_set_stencil (const int* lo, const int* hi,
                                    amrex_real* sten, const int* tlo, const int* thi,
                                    const amrex_real* sigma, const int* glo, const int* ghi,
                                    const amrex_real* dxinv);

    void amrex_mlndlap_set_stencil_s0 (const int* lo, const int* hi,
                                       amrex_real* sten, const int* tlo, const int* thi);

    void amrex_mlndlap_adotx_sten (const int* lo, const int* hi,
                                   amrex_real* y, const int* ylo, const int* yhi,
                                   const amrex_real* x, const int* xlo, const int* xhi,
                                   const amrex_real* sten, const int* slo, const int* shi,
                                   const int* dmsk, const int* dmlo, const int* dmhi);

    void amrex_mlndlap_normalize_sten (const int* lo, const int* hi,
                                       amrex_real* x, const int* xlo, const int* xhi,
                                       const amrex_real* sten, const int* slo, const int* shi,
                                       const int* dmsk, const int* dmlo, const int* dmhi,
                                       const amrex_real s0_norm0);

    void amrex_mlndlap_gauss_seidel_sten (const int* lo, const int* hi,
                                          amrex_real* sol, const int* slo, const int* shi,
                                          const amrex_real* rhs, const int* rlo, const int* rhi,
                                          const amrex_real* sten, const int* tlo, const int* thi,
                                          const int* dmsk, const int* dmlo, const int* dmhi);

    void amrex_mlndlap_jacobi_sten (const int* lo, const int* hi,
                                    amrex_real* sol, const int* slo, const int* shi,
                                    const amrex_real* Ax, const int* alo, const int* ahi,
                                    const amrex_real* rhs, const int* rlo, const int* rhi,
                                    const amrex_real* sten, const int* tlo, const int* thi,
                                    const int* dmsk, const int* dmlo, const int* dmhi);

    void amrex_mlndlap_restriction_rap (const int* lo, const int* hi,
                                        amrex_real* crse, const int* clo, const int* chi,
                                        const amrex_real* fine, const int* flo, const int* fhi,
                                        const amrex_real* sten, const int* tlo, const int* thi,
                                        const int* dmsk, const int* dmlo, const int* dmhi);
    
    void amrex_mlndlap_stencil_rap (const int* lo, const int* hi,
                                    amrex_real* csten, const int* clo, const int* chi,
                                    const amrex_real* fsten, const int* flo, const int* fhi);

    void amrex_mlndlap_interpolation_rap (const int* clo, const int* chi,
                                          amrex_real* fine, const int* fflo, const int* ffhi,
                                          const amrex_real* crse, const int* cflo, const int* cfhi,
                                          const amrex_real* sten, const int* tlo, const int* thi,
                                          const int* dmsk, const int* dmlo, const int* dmhi);

#ifdef AMREX_USE_EB

    void amrex_mlndlap_set_stencil_eb (const int* lo, const int* hi,
                                       amrex_real* sten, const int* tlo, const int* thi,
                                       const amrex_real* sigma, const int* glo, const int* ghi,
                                       const amrex_real* conn, const int* clo, const int* chi,
                                       const amrex_real* dxinv);

    void amrex_mlndlap_set_integral (const int* lo, const int* hi,
                                     amrex_real* intg, const int* glo, const int* ghi);

    void amrex_mlndlap_set_integral_eb (const int* lo, const int* hi,
                                        amrex_real* intg, const int* glo, const int* ghi,
                                        const void* flag, const int* flo, const int* fhi,
                                        const void* vol, const int* vlo, const int* vhi,
                                        const amrex_real* ax, const int* axlo, const int* axhi,
#if (AMREX_SPACEDIM >= 2)
                                        const amrex_real* ay, const int* aylo, const int* ayhi,
#endif
#if (AMREX_SPACEDIM == 3)
                                        const amrex_real* az, const int* azlo, const int* azhi,
#endif
                                        const amrex_real* bcent, const int* blo, const int* bhi);

    void amrex_mlndlap_set_connection (const int* lo, const int* hi,
                                       amrex_real* conn, const int* clo, const int* chi,
                                       const amrex_real* intg, const int* glo, const int* ghi,
                                       const void* flag, const int* flo, const int* fhi,
                                       const void* vol, const int* vlo, const int* vhi);

    void amrex_mlndlap_divu_eb (const int* lo, const int* hi,
                                amrex_real* rhs, const int* rlo, const int* rhi,
                                const amrex_real* vel, const int* vlo, const int* vhi,
                                const amrex_real* vfrac, const int* flo, const int* fhi,
                                const amrex_real* intg, const int* glo, const int* ghi,
                                const int* dmsk, const int* dmlo, const int* dmhi,
                                const amrex_real* dxinv);

    void amrex_mlndlap_mknewu_eb (const int* lo, const int* hi,
                                  amrex_real* u, const int* ulo, const int* uhi,
                                  const amrex_real* p, const int* plo, const int* phi,
                                  const amrex_real* sigma, const int* slo, const int* shi,
                                  const amrex_real* vfrac, const int* vlo, const int* vhi,
                                  const amrex_real* intg, const int* glo, const int* ghi,
                                  const amrex_real* dxinv);

    void amrex_mlndlap_rhcc_eb (const int* lo, const int* hi,
                                amrex_real* rhs, const int* rlo, const int* rhi,
                                const amrex_real* rhcc, const int* clo, const int* chi,
                                const amrex_real* vfrac, const int* flo, const int* fhi,
                                const amrex_real* intg, const int* glo, const int* ghi,
                                const int* dmsk, const int* mlo, const int* mhi);

#endif // AMREX_USE_EB


#ifdef __cplusplus
}
#endif

#endif
