/*
 * $Source$
 * $Author$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 *
 * For copying and distribution information, please see the file
 * <krb5/mit-copyright.h>.
 *
 * Return default cred. cache name.
 */

#if !defined(lint) && !defined(SABER)
static char rcsid_defname_c[] =
"$Id$";
#endif	/* !lint & !SABER */

#include <krb5/copyright.h>
#include <krb5/krb5.h>

#include <stdio.h>
#include <stdlib.h>

char *krb5_cc_default_name()
{
    char *name = getenv ("KRB5CCNAME");
    static char *name_buf;
    
    if (name == 0) {
	if (name_buf == 0)
	    name_buf = malloc (30);
	
	sprintf(name_buf, "/tmp/krb5cc_%d", getuid());
	name = name_buf;
    }
    return name;
}
    
