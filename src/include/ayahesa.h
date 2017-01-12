/**
 * Copyright (C) 2016 Quenza Inc.
 * All Rights Reserved
 *
 * This file is part of the Ayahesa core.
 *
 * Content can not be copied and/or distributed without the express
 * permission of the author.
 */

#ifndef _AYAHESA_H_
#define _AYAHESA_H_

#include "core/compat.h"
#include "core/defs.h"

#include <yajl/yajl_gen.h>
#include <yajl/yajl_tree.h>

#include <kore/kore.h>
#include <kore/http.h>
#include <kore/jsonrpc.h>

#define VERSION "Ayahesa/0.3"
#define CONFIG  "conf/framework.ini"
#define TESTCODE

#ifdef DEBUG
# define TESTCODE
#endif

#define T_FLAG_READONLY 0x1

/*
 * Application internal structure
 *
 * type:    Datatype
 * flags:   Additional tree options
 * key:     Key-value identifier
 * value:   Data object
 * child:   Child trees
 */
struct app_tree {
    enum {
        T_NULL = 0,
        T_INT,
        T_FLOAT,
        T_STRING,
        T_POINTER,
    } type;
    char flags;
    char *key;
    union {
        int i;
        float f;
        char *str;
        void *ptr;
    } value;
    struct {
        unsigned int alloc_cnt;
        struct app_tree **ptr;
    } child;
};

typedef struct app_tree app_t;

/* Core root definition */
extern app_t *root_app;

/*
 * Prototypes
 */
char *generate_instance_id(void);
const char *http_get_cookie(struct http_request *request, const char *name);

void application_create(app_t **app);
void application_config(app_t *app, const char *configfile);
void application_release(app_t *app);

int jrpc_write_string(struct jsonrpc_request *req, void *ctx);
int jrpc_write_string_array_params(struct jsonrpc_request *req, void *ctx);

#endif // _AYAHESA_H_