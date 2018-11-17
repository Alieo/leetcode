/*************************************************************************
	> File Name: 1_1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Nov 2018 06:24:58 PM CST
 ************************************************************************/
//hash
//O(n)
//思路: 将nums[i]全放入哈希表中, 用开放定址法处理冲突法. 若能在哈希中找到target - nums[i], target是两数之和.
typedef struct Data{
    int val,ind;
}Data;
typedef struct HastTable{
    Data *data;
    int *flag;
    int size;
}HashTable;
int hashFunc(int val){
    return val & 0x7fffffff;
}

HashTable *init(int n){
    HashTable * h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Data *)calloc(sizeof(Data),h->size);
    h->flag = (int *)calloc(sizeof(int),h->size);
    return h;
}

int insert(HashTable *h, int val,int ind){
    int hash = hashFunc(val);
    int pos = hash %  h->size;
    int times = 1;
    while(h->flag[pos]){
        pos +=(times *times);
        times++;
        pos %= h->size;
    }
    h->data[pos].val = val;
    h->data[pos].ind = ind;
    h->flag[pos] = 1;
    return 0;
}

Data *search(HashTable *h, int val){
    int hash = hashFunc(val);
    int pos = hash % h->size;
    int times = 1;
    while(h->flag[pos] && h->data[pos].val != val){
        pos +=(times *times);
        times++;
        pos %= h->size;
    }
    if(h->flag[pos] == 0) return NULL;
    return h->data + pos;
}

void clear(HashTable *h){
    if(h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

int* twoSum(int* nums, int numsSize, int target) {
    HashTable * h = init(numsSize);
    int *ret = (int *)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize ; i++){
        Data *result = search(h,target - nums[i]);
        if(result){
            ret[0] = result->ind;
            ret[1] = i;
            break;
        }
        insert(h,nums[i],i);
    }
    clear(h);
    return ret;
}
