//实现了大顶堆
int heap[maxn]//从1到n
void downAdjust(int low,int high){//low一般为要调整的节点，high一般为n
	int i=low;
	int j=low*2;
	while(j<=high){
		if(j+1<=high&&heap[j+1]>heap[j]){
			j=j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=i*2;
		}
		else{
			break;
		}
	}
}
void upAdjust(int low,int high){//low一般为1，high一般为要调整的节点
	int i=high；
	int j=i/2;
	while(j>=low){
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=i/2;
		}
		else{
			break;
		}
	}
}

void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
}

void deleteTop(){
	heap[1]=heap[n--];
	downAdjust(1,n);
}
void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
}

void heapsort(){
	createHeap();
	for(int i=n;i>1;i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
	}
}