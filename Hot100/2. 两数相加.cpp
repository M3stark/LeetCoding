/*
    2. 两数相加
    给你两个 非空 的链表，表示两个非负的整数。
    它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    难度：中等
    https://leetcode-cn.com/problems/add-two-numbers
*/

#include <iostream>
#include <vector>
using namespace std; // namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        int carry = 0; // 进位

        while (l1 || l2 || carry > 0) {
            int n1 = l1 == nullptr ? 0 : l1->val;
            int n2 = l2 == nullptr ? 0 : l2->val;
            int sum = n1 + n2 + carry;

            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy->next;
    }
};

/*
    创建链表
*/
ListNode *createNode(vector<int> &arr, int n)
{
    if (n == 0) {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *node = head;

    for (int i = 1; i < n; i++) {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }

    return head;
}

/*
    删除链表
*/
void deleteNode(ListNode *head)
{

    // ListNode *node = head;
    ListNode *node;
    while (head)
    {
        node = head->next;
        delete head;
        head = node;
    }
    return;
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

    cout << "nullptr" << endl;
    return;
}

/*
    输入一个vector
*/
template <typename T>
void fcin(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
    }
}

int main() 
{
    cout << "***********************************************" << endl;
    cout << "2. 两数相加" << endl;
    cout << "***********************************************" << endl;
    /*  创建第一个链表 */
    
}