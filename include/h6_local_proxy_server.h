#ifndef __H6_LOCAP_PROXY_SERVER__
#define __H6_LOCAP_PROXY_SERVER__

#include <pthread.h>
#include "listener.h"
#include "h6_basic_server.h"
#include "client.h"
#include "h6_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __h6_local_proxy_server       h6_local_proxy_svr_t;
typedef struct __h6_local_proxy_server_ops   h6_local_proxy_svr_ops;

struct __h6_local_proxy_server
{
    h6_svr_t            __upper;

    h6_bool_t           run;
    lsn_set_t           *lsn_set;
    client_set_t        *cli_set;
    
    h6_local_proxy_svr_ops  *ops;
};

struct __h6_local_proxy_server_ops
{
	int32_t (*init)(h6_local_proxy_svr_t *svr);
	void	(*fin)(h6_local_proxy_svr_t *svr);    
};

h6_local_proxy_svr_t *
h6_local_proxy_server_alloc(uint32_t size, h6_local_proxy_svr_ops *ops, void *u, const char *name);

int32_t
h6_local_proxy_server_bind_port(h6_local_proxy_svr_t *svr, uint16_t port);

void
h6_local_proxy_server_remove_port(h6_local_proxy_svr_t *svr, uint16_t port);

int32_t
h6_local_proxy_server_run(h6_local_proxy_svr_t *svr, int32_t loops);

__inline__ h6_bool_t
h6_local_proxy_server_is_running(h6_local_proxy_svr_t *svr);

void
h6_local_proxy_server_kill_unref(h6_local_proxy_svr_t *svr);

#ifdef __cplusplus
}
#endif

#endif
