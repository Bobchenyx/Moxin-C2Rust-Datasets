typedef struct LikeNode{
	int num;
	struct LikeNode * next;
}LN;

LN *create(int n){
	LN *l = (LN*)malloc(sizeof(LN));
	l->num = n%10;
	l->next = NULL;
	n /= 10;
	if(n == 0)return l;
	LN *p = NULL;
	while(n != 0){
		p = (LN*)malloc(sizeof(LN));
		p ->num = n%10;
		p->next = l;
		l = p;
		n /= 10;
	}		
	return l;
}

LN* reverse(LN *l){

	if(l ->next == NULL){
		
		return l;
	}
	else if(l->next->next == NULL){
		
		LN *p = l->next;
		l->next = NULL;
		p->next = l;
		l = p;
		return l;
	}
	else{	
	
		LN *p = l->next;
		LN *r = p->next;
		l->next = NULL;

		while(r != NULL){
			p->next = l;
			l = p;
			p = r;
			r = p->next;
		}

		p->next = l;
		l = p;
	}
	return l;
}


struct LikeNode* addTwoNumbers(struct LikeNode* l1, struct LikeNode* l2){

	LN *p = l1;
	LN *q = l2;
	int flag = 0;
	while(p != NULL && q != NULL){
		p->num = p->num + q->num + flag;
		if(p->num >= 10){
			p->num %= 10;
			flag = 1;
		}
		else{ flag = 0;}
		p= p->next;
		q= q->next;
	}
	LN*r = NULL;
	while(p != NULL){
		if(flag == 1){			
			p->num = p->num +flag;
			if(p->num >= 10){
				
				flag = 1;
				p->num %= 10;
			}
			else flag = 0;
		}

		p = p->next;

	}
	while( q != NULL ){
		p = l1;
		while(p->next != NULL){
			p = p->next;
		}
		r = (LN *)malloc(sizeof(LN));
		r->num = q->num +flag;
		if(r->num >= 10){
				
				flag = 1;
				r->num %= 10;
		}
		else flag = 0;
		r->next = NULL;
		p->next = r;
		p = r;
		q = q->next;
	}

	if(flag == 1){
		p = l1;
		while(p->next != NULL){
			p = p->next;
		}
		LN*r = (LN *)malloc(sizeof(LN));
		r->num = 1;
		r->next = NULL;
		p->next = r;
	}

	return l1;

}