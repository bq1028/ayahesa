/**
 * Copyright (C) 2017 Quenza Inc.
 * All Rights Reserved
 *
 * This file is part of the Ayahesa core.
 *
 * Content can not be copied and/or distributed without the express
 * permission of the author.
 */

#include <ayahesa.h>

/**
 * Foo controller
 *
 * Test the request information and set a cookie
 * when not done before. Report example text back.
 */
controller(foo)
{
    // kore_signal(SIGHUP);
    // abort();
    // return_ok();

    kore_msg_send(KORE_MSG_PARENT, KORE_MSG_SHUTDOWN, "1", 1);

//    const char *cookie = http_get_cookie(request, "authsess");

	//http_response_header(request, "content-type", "text/html");
//    if (cookie == NULL)
//	    http_response_header(request, "set-cookie", "authsess=dyfgyasdfwegfgwegrfw4i");

	http_response(request, 200, NULL, 0);

    return_ok();
}
