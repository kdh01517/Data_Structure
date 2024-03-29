```c
typedef struct s_list
{
	int data;
	struct s_node *next;
} t_list;

//선언
int arr[10];
t_list *lst;
'''

## 배열

```c
typedef struct s_list
{
	char	char_data;
	int		int_data;
	long long	index;
	struct s_list	*next;
	char	*type;
}	t_list;

//배열의 요소 생성하는 함수 -> index와 type을 여기서 지정
t_list	*new_element(int idx, char *type);
```

1. 선언 `data_type arr_name[arr_size];`

    ```c
    	t_list	*declare_an_array(char *type, long long size)
    {
    	int		idx;
    	t_list	*ret_arr;
    	t_list	*new_arr;
    	t_list 	*cur_arr;

    	idx = 0;
    	ret_arr = new_element(idx, type);
    	cur_arr = ret_arr;
    	while (++idx < size)
    	{
    		new_arr = new_element(idx, type);
    		ft_lstadd_back(&cur_arr, new_arr);
    	}
    	return (ret_arr);
    }
    ```

2. 초기화`data_type arr_name[arr_size] = {value};`

    선언과 동시에 초기화하는 경우, 초기화값을 지정하지 않은 인덱스 위치에는 0으로 초기화 됨.

    ```c
    void	initialize_an_array(t_list *arr, long long value)
    {
    	t_list	*cur_arr;
    	
    	cur_arr = arr;
    	while (cur_arr)
    	{
    		cur_arr->char_data = 0;
    		cur_arr->int_data = 0;
    		cur_arr = cur_arr->next;
    	}
    	insert_value(arr, 0, value);
    	return ;
    }
    ```

3. 대입 `arr_name[index] = value;`

    ```c
    void	insert_value(t_list *arr, long long index, long long value)
    {	
    	t_list	*cur_arr;

    	cur_arr = arr;
    	while (cur_arr)
    	{
    		if (cur_arr->index == index)
    		{
    			if (!strcmp(arr->type, "char"))
    				cur_arr->char_data = (char)value;
    			else if (!strcmp(arr->type, "int"))
    				cur_arr->int_data = (int)value;
    			return ;
    		}
    		cur_arr = cur_arr->next;
    	}
    }
    ```

4. 값 반환(탐색) `data_type temp = arr_name[index];`

    ```c
    int	return_value_of_array(t_list *arr, long long index)
    {
    	t_list	*cur_arr;

    	cur_arr = arr;
    	while (cur_arr)
    	{
    		if (cur_arr->index == index)
    		{	
    			if (!strcmp(cur_arr->type, "char"))
    				return (cur_arr->char_data);
    			else if (!strcmp(cur_arr->type, "int"))
    				return (cur_arr->int_data);
    		}
    		cur_arr = cur_arr->next;
    	}
    	return (-1);
    }
    ```

5. 값 화면에 출력

    ```c
    void	print_element(t_list *arr, long long index)
    {
    	t_list	*cur_arr;

    	cur_arr = arr;
    	while (cur_arr)
    	{
    		if (cur_arr->index == index)
    		{
    			if (!strcmp(cur_arr->type, "char"))
    				printf("array[%d]: %c\n", (int)index, cur_arr->char_ctnt);
    			else if (!strcmp(cur_arr->type, "int"))
    				printf("array[%d]: %d\n", (int)index, cur_arr->int_ctnt);
    			return ;
    		}
    		cur_arr = cur_arr->next;
    	}
    }
    ```

- 겪었던 문제
    - 문제는 → 하나의 구조체로 모든 타입의 배열을 처리하고자하여 데이터 값을 저장할 구조체 멤버변수를 void *형으로 선언
    - 원인 파악을 위해 → vscode 디버깅 툴을 사용
    - 원인은 → 0으로 초기화했을 때 널 포인터로 인식
    - 문제 원인을 없애기 위해 → 구조체에 char_data와 int_data라는 멤버를 따로 두고 char형 배열일 때에는 char_data에, int형 배열일 때에는 int_data에 값 저장

---

## 연결리스트


```c
typedef struct	s_list
{
	int				data;
	struct s_list	*next;
} t_list;
```

1. 리스트에 삽입할 노드 생성

```c
t_list	*new_element(int data);
```

1. 리스트에 노드 삽입(연결)

```c
void	insert_last_element(t_list *lst, int data);
void	insert_front_element(t_list **lst, int data);
void	insert_element(t_list *lst, int data, int index);
```

1. 리스트에서 삭제

```c
void	remove_element_idx(t_list **lst, int index);
void	remove_element_data(t_list **lst, int data);
void	remove_all(t_list **lst);
```

1. 리스트에서 특정 인덱스 위치에 있는 데이터 값 반환

```c
int		get_element_data(t_list *lst, int index);
```

1. 리스트에서 데이터의 위치(인덱스) 반환

```c
int		find_element_idx(t_cc_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
```

1. 리스트에서 값 바꾸기

```c
void	set_element_by_index(t_list *lst, int index, int new_data);
void	set_element_by_data(t_list *lst, int data, int new_data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
```

1. 리스트 정렬

```c
t_list	*sort_list_asc(t_list *lst);
t_list	*sort_list_desc(t_list *lst);
```

- 겪었던 문제
    - 문제는 → 리스트 정렬 시 최소(최대) 값을 가진 노드를 연결 끊어 제일 처음으로 넘기고자 함
    - 원인은 →  next만 가지고 있었기 때문에 리스트 순회 횟수가 많음
    - 문제 원인을 없애기 위해 → 기존 리스트를 끝까지 순회한 후 최소(최대) 값을 가진 노드를 삭제하고 다시 생성하여 새로운 리스트를 반환

---

## 원형연결리스트


```c
typedef struct	s_cc_list
{
	int				data;
	struct s_cc_list	*next;
} t_cc_list ;
```

1. 리스트에 삽입할 노드 생성

    ```c
    t_cc_list	*new_element(int data);
    ```

2. 리스트에 노드 삽입(연결)

    ```c
    void	insert_last_element(t_cc_list *lst, int data);
    void	insert_front_element(t_cc_list **lst, int data);
    void	insert_element(t_cc_list *lst, int data, int index);
    ```

3. 리스트에서 삭제

    ```c
    void	remove_element_idx(t_cc_list **lst, int index);
    void	remove_element_data(t_cc_list **lst, int data);
    void	remove_all(t_cc_list **lst);
    ```

4. 리스트에서 특정 인덱스 위치에 있는 데이터 값 반환

    ```c
    int		get_element_data(t_cc_list *lst, int index);
    ```

5. 리스트에서 데이터의 위치(인덱스) 반환

    ```c
    int		find_element_idx(t_cc_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
    ```

6. 리스트에서 값 바꾸기

    ```c
    void	set_element_by_index(t_cc_list *lst, int index, int new_data);
    void	set_element_by_data(t_cc_list *lst, int data, int new_data);
    ```

7. 리스트 정렬

    ```c
    t_cc_list	*sort_cc_list_asc(t_cc_list *lst);
    t_cc_list	*sort_cc_list_desc(t_cc_list *lst);
    ```

- 겪었던 문제
    - 문제는 → 실행 중 무한루프를 돎
    - 원인 파악을 위해 → vscode 디버깅 툴을 사용
    - 원인은 → 몇몇 함수에서 while문을 단순연결리스트 때처럼 cur이 0이 아닐 때를 조건으로 설정하고 있었기 때문(원형연결리스트에서는 cur은 늘 0이 아니게 됨)
    - 문제 원인을 없애기 위해 → cur→next ≠ list 를 while문 조건으로 설정

---

## 이중연결리스트


```c
typedef struct s_db_list
{
	int						data;
	struct s_db_list	*prev;
	struct s_db_list	*next;
} t_db_list;
```

1. 리스트에 삽입할 노드 생성

    ```c
    t_db_list	*new_element(int data);
    ```

2. 리스트에 노드 삽입(연결)

    ```c
    void	insert_last_element(t_db_list *lst, int data);
    void	insert_front_element(t_db_list **lst, int data);
    void	insert_element(t_db_list *lst, int data, int index);
    ```

3. 리스트에서 삭제

    ```c
    void	remove_element_idx(t_db_list **lst, int index);
    void	remove_element_data(t_db_list **lst, int data);
    void	remove_all(t_db_list **lst);
    ```

4. 리스트에서 특정 인덱스 위치에 있는 데이터 값 반환

    ```c
    int		get_element_data(t_db_list *lst, int index);
    ```

5. 리스트에서 데이터의 위치(인덱스) 반환

    ```c
    int		find_element_idx(t_db_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
    ```

6. 리스트에서 값 바꾸기

    ```c
    void	set_element_by_index(t_db_list *lst, int index, int new_data);
    void	set_element_by_data(t_db_list *lst, int data, int new_data); 
    ```

7. 리스트 정렬

    ```c
    t_db_list	*sort_db_list_asc(t_db_list *lst);
    t_db_list	*sort_db_list_desc(t_db_list *lst);
    ```

- 겪었던 문제
    - 문제는 → 실행 중 세그폴트가 뜨며 프로그램이 비정상적으로 종료됨
    - 원인 파악을 위해 → vscode 디버깅 툴을 사용함
    - 원인은 → 포인터 변수인 cur→next가 0인 상황에서 cur→next→prev와 같은 변수에 접근하려고 했던 것
    - 문제 원인을 없애기 위해 → if(cur→next ≠ 0) 일 때만 위와 같은 변수에 접근할 수 있게 해줌

---

## 이중원형연결리스트

```c
typedef struct s_cc_list
{
	int						data;
	struct s_cc_list	*prev;
	struct s_cc_list	*next;
} t_cc_list;
```

1. 리스트에 삽입할 노드 생성

    ```c
    t_cc_list	*new_element(int data);
    ```

2. 리스트에 노드 삽입(연결)

    ```c
    void	insert_last_element(t_cc_list *lst, int data);
    void	insert_front_element(t_cc_list **lst, int data);
    void	insert_element(t_cc_list *lst, int data, int index);
    ```

3. 리스트에서 삭제

    ```c
    void	remove_element_idx(t_cc_list **lst, int index);
    void	remove_element_data(t_cc_list **lst, int data);
    void	remove_all(t_cc_list **lst);
    ```

4. 리스트에서 특정 인덱스 위치에 있는 데이터 값 반환

    ```c
    int		get_element_data(t_cc_list *lst, int index);
    ```

5. 리스트에서 데이터의 위치(인덱스) 반환

    ```c
    int		find_element_idx(t_cc_list *lst, int data); // 중복 값이 있는 경우 제일 처음 인덱스 반환
    ```

6. 리스트에서 값 바꾸기

    ```c
    void	set_element_by_index(t_cc_list *lst, int index, int new_data);
    void	set_element_by_data(t_cc_list *lst, int data, int new_data); 
    ```

7. 리스트 정렬

    ```c
    t_cc_list	*sort_cc_list_asc(t_cc_list *lst); //오름차순 정렬
    t_cc_list	*sort_cc_list_desc(t_cc_list *lst); //내림차순 정렬
    ```

- 겪었던 문제
    - 문제는 → 실행 중 무한루프를 돎
    - 원인 파악을 위해 → vscode 디버깅 툴을 사용
    - 원인은 → remove 함수에서 어떤 한 노드를 연결리스트로부터 해제할 때 앞뒤로 모든 연결을 끊어줘야 하는데 그러지 않고 있었음
    - 문제 원인을 없애기 위해 → 없앨 노드 앞 노드의 next 값과, 없앨 노드 뒷 노드의 prev값을 알맞게 조정해줌
