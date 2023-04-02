#include<iostream>
using namespace std;
//��ֵ����
int strAssign(Str& str, char* ch)
{
	if (str.ch)
		free(str.ch);
	int len = 0;
	char* c = ch;
	while (*c)
	{
		len++;
		c++;

	}
	if (len == 0)
	{
		str.ch = NULL;
		str.length = 0;
		return 1;
	}
	else
	{
		str.ch = (char*)malloc(sizeof(char) * (len + 1));
		if (str.ch == NULL)
			return 0;
		else
		{
			c = ch;
			for (int i = 0; i <= len; i++, c++)
				str.ch[i] = *c;
			str.length = len;
			return 1;
		}
	}

}
//ȡ������
int strLength(Str str)
{
	return str.length;
}
//���Ƚ�
int strCompare(Str s1, Str s2)
{
	for (int i = 0; i < s1.length && i < s2.length; i++)
	{
		if (s1.ch[i] != s2.ch[i])
			return s1.ch[i] - s2.ch[i];//�ַ���ASCII��������
		return s1.length - s2.length;
	}
}
//������
int concat(Str& str, Str str1, Str str2)
{
	if (str.ch)//�ж�str.chΪ��Ϊ��,��Ϊ��ִ��if���
	{
		free(str.ch);
		str.ch = NULL;
	}
	str.ch = (char*)malloc(sizeof(char) * (str1.length + str2.length + 1));
	if (!str.ch)//str.chΪ��ִ��if���
		return 0;//�洢�ռ����ʧ�ܷ���0
	int i = 0;
	while (i < str1.length)
	{
		str.ch[i] = str1.ch[i];
		i++;
	}
	int j = 0;
	while (j <= str2.length)
	{
		str.ch[i + j] = str2.ch[j];
		j++;
	}
	str.length = str1.length + str2.length;
	return 1;
}
//���Ӵ�
int subString(Str& substr, Str str, int pos, int len)
{
	if (pos < 0 || pos >= len || len<0 || len >str.length - pos)
		return 0;
	if (substr.ch)
	{
		free(substr.ch)
		substr.ch = NULL;
	}
	if (len == 0)
	{
		substr.ch = NULL;
		substr.length = 0;
		return 1;
	}
	else
	{
		substr.ch = (char*)malloc(sizeof(char) * (len + 1));
		int i = pos;
		int j = 0;
		while (i < pos + len)
		{
			substr.ch[j] = substr.ch[i];
			i++;
			j++;
		}
		substr.ch[j] = '\0';
		substr.length = len;
		renturn 1;
	}
}
//��մ�
int clearString(Str& str)
{
	if (str.ch)
	{
		free(str.ch);
		str.ch = NULL;
	}
	str.length = 0;
	return 1;
}
//��next����
void getNext(Str sybstr, int next[])
{
	int j = 1, t = 0;
	next[1] = 0;
	while (j < substr.length)
	{
		if (t == 0 || substr.ch[j] == substr.ch[t])
		{
			next[j + 1] = t + 1;
			t++;
			j++;
		}
		else
			t = next[t];
	}
}
//KMP�㷨
int KMP(Str str, Str sybstr, int next[])
{
	int i = 1, j = 1;
	while (i <= str.length && j <= substr.ch[j])
	{
		if (j == 0 || str.ch[i] == substr.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
    if(j > substr.length)
    {
		return i - substr.length;
	}
	else
	{
		return 0;
	}

}
//nextval����
void getNextval(Str substr, int nextval[], int next[])
{
	int j = 1, t = 0;
	next[1] = 0;
	nextval[1] = 0;
	while (j < substr.length)
	{
		if (t == 0 || substr.ch[j] == substr.ch[t])
		{
			next[j + 1] = t + 1;
			if (substr.ch[j + 1] != substr.ch[t + 1])
				nextval[j + 1] = t+1;
			else
				nextval[j + 1] = nextval[t + 1];
			j++;
			t++;
		}
		else
			t = nextval[t];
	}
}
