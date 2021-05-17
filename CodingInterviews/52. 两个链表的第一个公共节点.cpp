/*
    剑指 Offer 52. 两个链表的第一个公共节点
    输入两个链表，找出它们的第一个公共节点。
    难度；简单
    https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
*/

/*
    *****************************************************************************************
    * WARNING: This code is not true for recently.  
    *****************************************************************************************
    * Notes:
    * In leetcode playground page, the function of getIntersectionNode seems like ->
    * ListNode* getIntersectionNode(intersectVal, listA, listB, skipA, skipB);
    * however, in the problems, the functions seems like difference, just like ->
    * ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {}
    * So, I just confused how does it work.
    * If you guys have any idea, please let me know.
    * Thank you so much.
    *****************************************************************************************
*/

/*
    输入输出：
    输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
    输出：Reference of the node with value = 8
*/

#include <iostream>
#include <vector>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;

        while (curA != curB)
        {
            curA = curA == nullptr ? headB : curA->next;
            curB = curB == nullptr ? headA : curB->next;
        }

        return curA;
    }
};


/*
    创建链表
*/
ListNode *createNode(vector<int>& arr, int n)
{
    if (n == 0)
    {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *node = head;
    for (int i = 1; i < n; i++)
    {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }

    return head;
}

/*
    打印链表
*/
void printNode(ListNode *head)
{
    ListNode *curNode = head;
    cout << "ListNode is: ";
    while (curNode != NULL)
    {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;
    return;
}

/*
    删除链表
*/
void deleteNode(ListNode *head)
{

    // ListNode *node = head;
    ListNode* node;
    while (head)
    {
        node = head->next;
        delete head;
        head = node;
    }
    return;
}

/*
    输入一个vector
*/
template<typename T>
void fcin(vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

int main()
{
    cout << "***********************************************" << endl;
    cout << "剑指 Offer 52. 两个链表的第一个公共节点" << endl;
    cout << "***********************************************" << endl;
    /*  创建第一个链表 */
    int m;
    cout << "请输入链表A的大小: ";
    cin >> m;
    vector<int> vA(m);
    fcin(vA);
    ListNode* listA = createNode(vA, m);
    printNode(listA);
    /*  创建第二个链表 */
    int n;
    cout << "请输入链表B的大小: ";
    cin >> n;
    vector<int> vB(n);
    fcin(vB);
    ListNode *listB = createNode(vB, n);
    printNode(listB);
    /*  Solution   */
    Solution a;
    ListNode* res;
    res = a.getIntersectionNode(listA, listB);
    /*  res  */
    if(res == nullptr) {
        cout << "Reference of the node with value: nullptr" << endl;
    }
    else {
        cout << "Reference of the node with value: " << res->val;
    }
    // cout << "Reference of the node with value: " << res->val;
    cout << "***********************************************" << endl;
    /*  delete ListNode */
    deleteNode(listA);
    deleteNode(listB);
    deleteNode(res);

    return 0;
}