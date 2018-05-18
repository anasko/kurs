#ifndef ALU_H
#define ALU_H

int ALU(int command, int operand);

int READ(int operand);
int WRITE(int operand);

int LOAD(int operand);
int STORE(int operand);

int ADD(int operand);
int SUB(int operand);
int DIVIDE(int operand);
int MUL(int operand);

int JUMP(int operand);
int JNEG(int operand);
int JZ(int operand);
int HALT();

int JP(int operand);


#endif 
