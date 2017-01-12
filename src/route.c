/**
 * Copyright (C) 2017 Quenza Inc.
 * All Rights Reserved
 *
 * This file is part of the Ayahesa core.
 *
 * Content can not be copied and/or distributed without the express
 * permission of the author.
 */

/*
|--------------------------------------------------------------------------
| Web Routes & Endpoint Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are called when a configuration URI is hit. Keep the routes
| simple and move any operations or actions into a controller or unit 
| method. Now create something great!
|
*/

#include <ayahesa.h>

/*
 * Default routes with quick return
 */
route(report) { write_plain("Reporting back"); }
route(html) { write_html("<b>Important!</b>"); }
route(root) { redirect("/app/main"); }

/*
 * Welcome page, show some framework love
 */
route(main)
{
	const char *default_page = 
		"<html>"
		"<head><title>Welcome</title></head>"
		"<body>"
		"<h1>Welcome to Ayahesa</h1>"
		"</body>"
		"</html>";

    /* Only accept GET requests */
	http_get();

	http_response_header(request, "content-type", "text/html");
	http_response_header(request, "set-cookie", "_umaysess=3745693");
	http_response(request, 200, default_page, strlen(default_page));

	/* We're good */
	return_ok();
}

/*
 * Handle request in controller
 */
route(foo)
{
    invoke(foo);

	/* We're good */
	return_ok();
}

/*
 * JSON-RPC Endpoint
 */
endpoint(core)
{
	jrpc_parse();

	/* Return status OK */
	if (!strcmp(request.method, "status")) {
		return jsonrpc_result(&request, jrpc_write_string, "OK");
	}

	/* Call controller */
	jrpc_invoke("echo", echo);
	jrpc_invoke("date", date);

	/* No method found */
	jrpc_return_error();
}
