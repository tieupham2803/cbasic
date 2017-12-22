void replace(char str[], char replace_what, char replace_with){
	int i;
	for ( i = 0; str[i]!= '\0'; ++i)
	{
		/* code */
		if(str[i] == replace_what)
			str[i]  = replace_with;
	}
}