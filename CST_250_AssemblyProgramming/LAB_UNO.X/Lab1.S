/* Kayleb Cook, 10/5/24 
    */

#include <p32xxxx.h>
.global main
.set noreorder

.data
    var_a: .word 0x7fffffff // initializing var_a
    var_b: .space  4 // setting space in var_b and var_c
    var_c: .space  4 // "     "

.text
main: 
    li t0 , 0x10000000 // hex value for b
    sw t0, var_b
    lw t1, var_a
    
    addu t0, t1, t0 // adding the two variables together
    sw t0, var_c

        
    j .
    nop