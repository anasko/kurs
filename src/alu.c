#include <stdio.h>
#include "../include/alu.h"
#include "../include/sc.h"
#include "../include/gui.h"

int ALU(int command, int operand)
{
    if (command == 10)
        return READ(operand);
    else if (command == 11)
        return WRITE(operand);
    else if (command == 20)
        return LOAD(operand);
    else if (command == 21)
        return STORE(operand);
    else if (command == 30)
        return ADD(operand);
    else if (command == 31)
        return SUB(operand);
    else if (command == 32)
        return DIVIDE(operand);
    else if (command == 33)
        return MUL(operand);
    else if (command == 40)
        return JUMP(operand);
    else if (command == 41)
        return JNEG(operand);
    else if (command == 42)
        return JZ(operand);
    else if (command == 43)
        return HALT();
    else if (command == 58)
        return JP(operand);
    
    sc_regSet(COMMAND_ERR, 1);
    return -1;
}

int READ(int operand)
{
    input_plz(operand);
    return 0;
}

int WRITE(int operand)
{
    output(operand);
    return 0;
}

int LOAD(int operand) 
{
    int value = 0;
    sc_memoryGet(operand, &value);
    sc_accumSet(value);
    return 0;
}

int STORE(int operand)
{
    int a = 0;
    sc_accumGet(&a);
    sc_memorySet(operand, a);
    return 0;
}

int ADD(int operand)
{
    int a = 0;
    sc_memoryGet(operand, &a);
    int b = 0;
    sc_accumGet(&b);
    b += a;
    sc_accumSet(b);
    return 0;
}

int SUB(int operand)
{
    int a = 0;
    sc_memoryGet(operand, &a);
    int b = 0;
    sc_accumGet(&b);
    b -= a;
    sc_accumSet(b);
    return 0;
}

int DIVIDE(int operand)
{
    int a = 0;
    sc_memoryGet(operand, &a);
    int b = 0;
    sc_accumGet(&b);
    if (a == 0)
        sc_regSet(ZERO_ERR, 1);
    b /= a;
    sc_accumSet(b);
    return 0;
}

int MUL(int operand)
{
    int a = 0;
    sc_memoryGet(operand, &a);
    int b = 0;
    sc_accumGet(&b);
    b *= a;
    sc_accumSet(b);
    return 0;
}

int JUMP(int operand)
{
    sc_instSet(--operand);
    return 0;
}

int JNEG(int operand)
{
    int tmp = 0;
    sc_accumGet(&tmp);
    if (tmp <= 0)
        sc_instSet(--operand);
    return 0;
}

int JZ(int operand)
{
    int tmp = 0;
    sc_accumGet(&tmp);
    if (tmp == 0)
        sc_instSet(--operand);
    return 0;
}

int HALT()
{
    sc_regSet(FREQ_ERR, 1);
    sc_instSet(0);
    return 0;
}

int JP(int operand)
{
    int tmp = 0;
    sc_accumGet(&tmp);
    if (!(tmp % 2))
        sc_instSet(operand);
    return 0;
}




