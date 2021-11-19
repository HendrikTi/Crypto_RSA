/*
RSA Test-Implementation for Side-Channel-Attack on Microcontroller
 */

#include "flint.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>




int main() {
    
    /*
    char *p_str = "3";
    char *q_str = "5";
    char *d_str = "7";
    char *e_str = "7";
     char *m_str = "2";
      char *n_str = "15";
      char *one_str = "1";
      */
     
    char *p_str = "111825453771859250150386440972918554728461038710893791329703154089907481147801";
    char *q_str = "108573832589805988142309879468578719706310897875905346101420492940046196456631";
    char *d_str = "2775179594650837290788685878833912480610011253565122449948690518078682110699715074898589376818865486289115528173768778218466977230159723313414439814033473";
    char *e_str = "65537";
    char *m_str = "2";
    char *n_str = "12141318097104934814847670656951810563533932411541884512836270392745166187512051298059983293314259810801734178844814239099715656729752738252586838997518431";
    char *one_str = "1";
    


    CLINT q, p, dq, dp, temp, temp1, temp3, temp4 , temp2, d, u, v, d_one, sigp, sigq, m, sig, n, one;
    str2clint_l (one, one_str, 10);
    str2clint_l (p, p_str, 10);
    str2clint_l (q, q_str, 10);
    str2clint_l (d, d_str, 10);
    str2clint_l (m, m_str, 10);
    str2clint_l (n, n_str, 10);

    /*  1. dp = d mod(p-1) and dq = d mod(q-1)
        2. 1 = up+vq
        3. sigp = m^(dp) mod p and sigq = m^(dq) mod q
        4. sig = u p sigq + v sigp mod n

        n = 35
        phi(n) = (p-1)(q-1) = 24
        e = 23
        d = 23


    */



    /* Step 1 */
    sub_l(p,one, temp);
    printf("p-1: %s\n", xclint2str_l(temp, 10, 0));
    mod_l(d, temp , dp);
    sub_l(q,one, temp);
    mod_l(d, temp , dq);

    /* Step 2 */
    int sigu, sigv, sigsig;
    int errcode;

    xgcd_l (p, q, d_one, u, &sigu, v, &sigv);

    /* Step 3 */
    errcode = mexpk_l(m, dp, sigp, p);
    printf("%d", errcode);
    errcode = mexpk_l(m, dq, sigq, q);
    printf("%d", errcode);

    /* Step 4 */
    
    errcode = mul_l(u, p, temp);
    errcode = mul_l(temp, sigq, temp3);
    errcode = mul_l(v, q, temp);
    errcode = mul_l(temp, sigp, temp4);
    sigsig = sadd(temp3, sigu,temp4, sigv, temp);
    smod(temp, sigsig, n, sig);
    printf("%d", errcode);



    printf("One: %s\n", xclint2str_l(one, 10, 0));
    printf("d_one: %s\n", xclint2str_l(d_one, 10, 0));
    printf("n: %s\n", xclint2str_l(u, 10, 0));
    printf("v: %s\n", xclint2str_l(v, 10, 0));
    printf("dp: %s\n", xclint2str_l(dp, 10, 0));
    printf("dq: %s\n", xclint2str_l(dq, 10, 0));
    printf("sig: %s\n", xclint2str_l(sig, 10, 0));
    printf("sigp: %s\n", xclint2str_l(sigp, 10, 0));
    printf("sigq: %s\n", xclint2str_l(sigq, 10, 0));

    getchar();

    return 0;
}