text *text_Make(unsigned int len, unsigned int limit){
	if(limit < len)
		return NULL;

	text ret  = malloc(sizeof(text));
	if(ret == NULL){
		return NULL;
	}
	char body = malloc(sizeof(char) * len);
	if(body == NULL){
		free(ret);
		return NULL;
	}

	ret.len = len;
	ret.limit = limit;
	ret.body = &body;
	body[0] = '\0';
	return &ret;
}
void text_Delete(text *target){
	free(target->body);
	free(target);
}
void text_Copy_rigid(
		text *src, 
		text *dst, 
		unsigned int srcStart, 
		unsigned int dstStart,
		unsigned int len){

	int dstCapacity = dst->len - dstStart;
}
char *text_Copy_flex(char *src, char *dst){}
