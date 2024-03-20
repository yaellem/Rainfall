class N {

	public: 
	/***/*	
		N(char *s, int i){	
			*s = &operator+; //*s = "\x08\x04\x88\x48"
			*(s+0x68) = i;	
		}					
		
		setAnnotation(char *s, char *input){
			int input_len = strlen(input);
			memcpy((char*)(s + 4), input, input_len);
		}
		
		int operator+(char *s2, char *s1){
			i = *(s2 + 0x68) 
			j = *(s1 + 0x68)
			return (i + j);
		}
		
		void *operator new(size_t size){
        	 void *p = malloc(size);
	         return p;
        }
}

int main(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	char *s1 = operator.new(0x6c);

	N::N(s1, 5);
	
	char *s2 = operator.new(0x6c);

	N::N(s2, 6); 
	
	N::setAnnotation(s1, av[1])

	((void(*)(void))**s2)(s2, s1);
	return 0;
}

