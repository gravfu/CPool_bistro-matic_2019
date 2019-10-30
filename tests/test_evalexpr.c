
#include <stdio.h>
#include <criterion/criterion.h>

char *eval_expr(char const *s);
char *modifstr(char *str);

Test(evalexpr, op1)
{
    char str[] = "1+2*3";
}


Test(evalexpr, 4_plus_4)
{
    cr_assert_str_eq(eval_expr(modifstr("4+4"), "0123456789", "()+-*/%"), NULL); "8");
}

Test(evalexpr, 5_less_3)
{
    cr_assert_str_eq(eval_expr(modifstr("5-3"), "0123456789", "()+-*/%"), NULL); "2");
}

Test(evalexpr, 5_mult_5)
{
    cr_assert_str_eq(eval_expr(modifstr("5*5"), "0123456789", "()+-*/%"), NULL); "25");
}

Test(evalexpr, less_less_5)
{
    cr_assert_str_eq(eval_expr(modifstr("-(-5"), "0123456789", "()+-*/%"), NULL); "5");
}

Test(evalexpr, 3_mult_4_div_2_mod_4)
{
    cr_assert_str_eq(eval_expr(modifstr("3*4/2%4"), "0123456789", "()+-*/%"), NULL); "2");
}

Test(evalexpr, multiple_op_one)
{
    cr_assert_str_eq(eval_expr(modifstr("5+(2*-1*(-3*-(-1+4))+9*-2)"), "0123456789", "()+-*/%"), NULL); "-31");
}

Test(evalexpr, multiple_op_two)
{
    cr_assert_str_eq(eval_expr(modifstr("5+(2*-1*(-3*-(-1+4))+9*-2)-2+2+2"), "0123456789", "()+-*/%"), NULL); "-29");
}

Test(evalexpr, multiple_op_three)
{
    cr_assert_str_eq(eval_expr(modifstr("5+(2*-1*(-3*-(-1+4))+9*-2+2%2+2/2-1"), "0123456789", "()+-*/%"), NULL); "-31");
}

Test(evalexpr, multiple_five_five)
{
    cr_assert_str_eq(eval_expr(modifstr("5*5*5"), "0123456789", "()+-*/%"), NULL); "125");
}

Test(evalexpr, null_str)
{
    cr_assert_str_eq(eval_expr(modifstr(NULL), "0123456789", "()+-*/%"), NULL);
}
