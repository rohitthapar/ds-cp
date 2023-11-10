#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = new struct Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == nullptr)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void createLeftViewArray(struct Node* root, int level, int& maxLevel, vector<int>& leftViewArray) {
    if (root == nullptr)
        return;

    if (level > maxLevel) {
        leftViewArray.push_back(root->data);
        maxLevel++;
    }

    createLeftViewArray(root->left, level + 1, maxLevel, leftViewArray);
    createLeftViewArray(root->right, level + 1, maxLevel, leftViewArray);
}

bool isPalindrome(const vector<int>& arr) {
    int size = arr.size();
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        if (arr[i] != arr[j])
            return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    struct Node* root = nullptr;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        root = insert(root, num);
    }

    vector<int> leftViewArray;
    int maxLevel = 0;
    string s  = "";
    createLeftViewArray(root, 1, maxLevel, leftViewArray);
    for(int i=0;i<leftViewArray.size();i++){
        s += to_string(leftViewArray[i]);
    }
    int i = 0, e = s.size()-1;
    bool flag = true;
    while(i < e){
        if(s[i] != s[e]){
            flag = false;
            break;
        }
        i++;e--;
    }
    if(flag == false) cout << "NOT PALINDROME";
    else {
        for(int i=0;i<s.size();i++){
            cout << s[i] - '0' << " ";
        }
    }

    return 0;
}
