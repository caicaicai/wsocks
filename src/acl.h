
#ifndef _ACL_H_
#define _ACL_H_

#include <sys/types.h>
#include <stdio.h>

#include "list.h"

typedef void* (acl_parse_t) (const char *parameter, int *eat, int *err);
typedef int (acl_snprint_t) (char *buf, size_t size, void *acl_priv);
typedef void (acl_free_t) (void *acl_priv);

#define ACL_PARSE_PTR(x) ((acl_parse_t*)(x))
#define ACL_SNPRINT_PTR(x) ((acl_snprint_t*)(x))
#define ACL_FREE_PTR(x) ((acl_free_t*) (x))

typedef struct acl
{
	struct list rule;
	struct list cond_mod;
	struct list act_mod;
	struct list cond_path;
	struct list act_path;
} acl_t;

void acl_init(acl_t *acl);
acl_t* acl_new(void);
void acl_free(acl_t *acl);
int acl_parse(acl_t *acl, const char *rule_str);
int acl_do(acl_t *acl, void *cond_param, void *act_param);
int acl_load_from_FILE(acl_t *acl, FILE *fh);
int acl_load_to_FILE(acl_t *acl, FILE *fh);
int acl_load_from_file(acl_t *acl, const char *file);
int acl_load_to_file(acl_t *acl, const char *file);

#endif /* _ACL_H_ */
