/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/
/*char* rev(char *arr);
bool isValid(char* s) {
    char * arr;
    arr= rev(s);
    if(strcmp(s,arr)==1){
        return true;
    }
    else{
        return false;
    }
}
char* rev(char *arr){
    int n = strlen(arr);
    int start = n/2;
    int end = n-1;
    while(end>start){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        end--;
        start++;
    }
    return arr;
}*/
bool isValid(char* s) {
    int n = strlen(s);
    char *stack = malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) { free(stack); return false; }
            char t = stack[top--];
            if (c == ')' && t != '(') { free(stack); return false; }
            if (c == '}' && t != '{') { free(stack); return false; }
            if (c == ']' && t != '[') { free(stack); return false; }
        }
    }

    bool res = top == -1;
    free(stack);
    return res;
}