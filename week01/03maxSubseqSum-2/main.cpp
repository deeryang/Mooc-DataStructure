#include <stdio.h>

int main()
{
    int n, flag = 1, first_flag = 1, positive_flag = 0;
    int sum = 0, summax = 0;
    int st = 0, end = 0, st_max = 0, end_max = 0, first = 0, last = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &last);
        if (last >= 0) {
            positive_flag = 1;   // 检查是否有正数，有正数则正数标记置1
        }
        if (first_flag) {
            first = last;        // 因为没用数组记录所有数据，这里就要用一个标记判断并记录第一个数据
            first_flag = 0;
        }
        if (flag) {
            st = last;           // 当sum < 0的时候要将下一项设为新的子列的开始项，
            flag = 0;            // 但是因为那时还没读取，所以就用一个标记记录这件要做的事，
        }                        // 在下一个循环完成。

        sum += last;
        end = last;
        if (summax < sum) {      // 当前子列和小于最大和时，更新最大和，最大子列首项和末项
            summax = sum;
            st_max = st;
            end_max = end;
        }
        if (sum < 0) {           // 同上面flag项解释，这里flag置1，sum清零
            sum = 0;
            flag = 1;
        }
    }
    if (positive_flag)
        printf("%d %d %d", summax, st_max, end_max);
    else
        printf("%d %d %d", summax, first, last);
    return 0;
}
