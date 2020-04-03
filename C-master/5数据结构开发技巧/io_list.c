int io_list_len(Eterm obj)  
{  
    Eterm* objp;  
    Sint len = 0;  
    DECLARE_ESTACK(s);  
    goto L_again;  
  
    while (!ESTACK_ISEMPTY(s)) {  
        obj = ESTACK_POP(s);  
    L_again:  
        if (is_list(obj)) {  
		        L_iter_list:  
		            objp = list_val(obj);  
	            /* Head */  
	            obj = CAR(objp);  
		         if (is_byte(obj)) {  
		             len++;  
		         } else if (is_binary(obj) && binary_bitsize(obj) == 0) {  
		             len += binary_size(obj);  
		         } else if (is_list(obj)) {  
		             ESTACK_PUSH(s, CDR(objp));  
		             goto L_iter_list; /* on head */  
		         } else if (is_not_nil(obj)) {  
		             goto L_type_error;  
		         }  
	            

	            /* Tail */  
	            obj = CDR(objp);  
	            if (is_list(obj))  
	                goto L_iter_list; /* on tail */  
	            else if (is_binary(obj) && binary_bitsize(obj) == 0) {  
	                len += binary_size(obj);  
	            } else if (is_not_nil(obj)) {  
	                goto L_type_error;  
	            }

        } else if (is_binary(obj) && binary_bitsize(obj) == 0) { /* Tail was binary */  
            len += binary_size(obj);  
        } else if (is_not_nil(obj)) {  
            goto L_type_error;  
        }  
    }  
  
    DESTROY_ESTACK(s);  
    return len;  
  
 L_type_error:  
    DESTROY_ESTACK(s);  
    return -1;  
}  