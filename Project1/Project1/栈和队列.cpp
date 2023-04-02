#include<iostream>
using namespace std;
#define maxSize
//中缀转后缀
int getPriority(char i)
//得到符号的优先级
{
	switch (i)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
}
void infixToPostFix(char infix[], char s2[], int& top2)     //s2结果栈
{
	char s1[maxSize];      //s1辅助栈
	int top1 = -1;
	int i = 0;
	while (infix[i] != '\0')
	{
		if ('0' <= infix[i] && infix[i] <= '9')
		{
			s2[++top2] = infix[i];//top++;s2[top2] = infix[i];
			i++;
		}
		else if (infix[i] == '(')
		{
			s1[++top1] = '(';
			i++;
		}
		else if (infix[i] == '+' ||
			infix[i] == '-' ||
			infix[i] == '*' ||
			infix[i] == '/')
		{
			if (top1 == -1 || s1[top1] == '(' || getPriority(infix[i]) > getPriority(s1[top1]))
			{
				s1[++top1] = infix[i];
				i++;
			}
			else
			{
				s2[++top2] = s1[top1--];
			}
		}
		else if (infix[i] == ')')
		{
			while (s1[top1] != '(')
				s2[++top2] = s1[top1--];
			top1--;
			i++;
		}
	}
	while (top1 != -1)
		s2[++top2] = s1[top1--];
}
//中缀转前缀
void infixToPreFix(char infix[], int len, char s2[], int& top2)
{
	char s1[maxSize];
	int top1 = -1;
	int i = len - 1;
	while (i >= 0)
	{
		if ('0' <= infix[i] && infix[i] >= '9')
		{
			s2[++top2] = infix[i];
			i--;
		}
		else if (infix[i] = ')')
		{
			s1[++top1] = ')';
			i--;
		}
		else if (infix[i] == '+' ||
			infix[i] == '-' ||
			infix[i] == '*' ||
			infix[i] == '/'  )
		{
			if (top1 == -1 || s1[top1] == ')' || getPriority(infix[i]) >= getPriority(s1[top1]))
			{
				s1[++top1] = infix[i];
				i--;
			}
			else
				s2[++top2] = s1[top1--];
		}
		else if (infix[i] = '(')
		{
			while (s1[top1] != ')')
				s2[++top2] = s1[top1--];
			top1--;
			i--;
		}
	}
	while (top1 != -1)
		s2[++top2] = s1[top1--];
}
//用栈实现表达式求值
//求中缀表达式的值
int getPriority(char op)
{
	if (op == '+' || op == '-')
		return 0;
	else
		return 1;
}
int calsub(float opand1, char op, float opand2, float& result)
{
	if (op == '+')
		result = opand1 + opand2;
	if (op == '-')
		result = opand1 - opand2;
	if (op == '*')
		result = opand1 * opand2;
	if (op == '/')
	{
		if (fabs(opand2) < MIN)    //fabs 函数用于对浮点数 float 或者 double 或者整数 int 取绝对值
			return 0;
		else
			result = opand1 / opand2;
	}
	return 1;
}
float calInfix(char exp[])
{
	float s1[maxSize];
	int top1 = -1;
	char s2[maxSize];
	int top2 = -1;
	int i = 0;
	while (exp[i] != '\0')
	{
		if ('0' <= exp[i] && exp[i] <= '9')
		{
			s1[++top1] = exp[i] - '0';//把字符型0~9转化为数字0~9（ASCII码0~9顺序依次递增1）
			i++;
		}
		else if (exp[i] == '(')
		{
			s2[++top2] = '(';
				i++;
		}
		else if (exp[i] == '+' ||
			exp[i] == '-' ||
			exp[i] == '*' ||
			exp[i] == '/')
		{
			if (top2 == -1 || s2[top2] == '(' || getPriority(exp[i]) > getPriority(s2[top2]))
			{
				s2[++top2] = exp[i];
				i++;
			}
			else
			{
				float opnd1, opnd2, result;//可以改写成函数形式，简化3段重复代码
				char op;
				int flag;
				opnd2 = s1[top1--];
				opnd1 = s1[top1--];
				op = s2[top2--];
				flag = calsub(opnd1, op, opnd2, result);
				if (flag == 0)
				{
					cout << "ERROR" << endl;
					return 0;
				}
				s1[++top1] = result;

			}
		}
		else if (exp[i] == ')')
		{
			while (s2[top2] != '(')
			{
				float opnd1, opnd2, result;
				char op;
				int flag;
				opnd2 = s1[top1--];
				opnd1 = s1[top1--];
				op = s2[top2--];
				flag = calsub(opnd1, op, opnd2, result);
				if (flag == 0)
				{
					cout << "ERROR" << endl;
					return 0;
				}
				s1[++top1] = result;
			}
			top2--;
			i++;
		}
	}
	while (top2 != -1)
	{
		float opnd1, opnd2, result;
		char op;
		int flag;
		opnd2 = s1[top1--];
		opnd1 = s1[top1--];
		op = s2[top2--];
		flag = calsub(opnd1, op, opnd2, result);
		if (flag == 0)
		{
			cout << "ERROR" << endl;
			return 0;
		}
		s1[++top1] = result;
	}
	return s1[top1];
}
//求后缀表达式的值
float calPostFix(char exp[])
{
	float s[maxSize];
	int top = -1;
	int i = 0;
	while (exp[i] != '\0')
	{
		if ('0' <= exp[i] && exp[i] >= '9')
		{
			s[++top] = exp[i] - '0';
		}
		else if (exp[i] == '+' ||
			exp[i] == '-' ||
			exp[i] == '*' ||
			exp[i] == '/')
		{
			float opnd1, opnd2, result;
			char op;
			int flag;
			opnd2 = s[top--];
			opnd1 = s[top--];
			op = exp[i];
			flag = calsub(opnd1, op, opnd2, result);
			if (flag == 0)
			{
				cout << "ERROR" << endl;
				break;
			}
			s[++top] = result;
		}
		i++;
	}
	return s[top];
}
//求前缀表达式的值
float calPreFix(char exp[], int len)
{
	float s[maxSize];
	int top = -1;
	for (int i = len - 1; i >= 0; i--)
	{
		if ('0' <= exp[i] && exp[i] >= '9')
		{
			s[++top] = exp[i] - '0';
		}
		else
		{
			float opnd1, opnd2, result;
			char op;
			opnd1 = s[top--];
			opnd2 = s[top--];
			op = exp[i];
			flag = calsub(opnd1, op, opnd2, result);
			if (flag == 0)
			{
				cout << "ERROR" << endl;
				return 0;
			}
			s[++top] = result;
		}
	}
	return s[top];
}
//括号匹配
int isMatched(char left, char right)
{
	if (left == '(' && right == ')')
		return 1;
	else if (left == '[' && right == ']')
		return 1;
	else if (left == '{' && right == '}')
		return 1;
	else
		return 0;
}
int isParentheseBalanced(char exp[])
{
	char s[maxSize];
	int top = -1;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s[++top] = exp[i];
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (top == -1)
				return 0;
			char left = s[top--];
			if (isMatched(left, exp[i]) == 0)
				return 0;
		}
	}
	if (top > -1)
		return 0;
	return 1;
}
//计算F(m)=m*F(m/3),m>0;F(m)=1,m=0.
int calF(int m)
{
	int cum = 1;
	int s[maxSize], top = -1;
	while (m != 0)
	{
		s[++top] = m;
		m /= 3;//m = m/3;
	}
	while (top != -1)
		cum *= s[top--];//cum=cum*s[top];top--;
	return cum;
}