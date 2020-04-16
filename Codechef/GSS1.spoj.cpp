#include<iostream>
#include<math.h>
using namespace std;

class Node {
    Node(int val){
        this->val = val;
    }

    Node(int val, Node *left, Node *right){
        this->val = val;
        this->right = right;
        this->left = left;
    }

    int val;
    Node *left;
    Node *right;
};

Node* make_tree(vector<int> &vec, int start, int end){
    if(start == end){
        return new Node(vec[start]);
    }
    Node *left = make_tree(vec, start, (start + end) /2);
    Node *right = make_tree(vec, (start + end) / 2 + 1, end);
    return new Node(min(left->val, right->val), left, right);
}

int get_value(Node* node, int start, int end, int size){
    if(start == end){
        return node->val;
    }
    if(start > size/2){
        return get_value(node->right, start - size/2, end - size / 2, size / 2);
    } else if(end < size/2){
        return get_value(node->left, start, end, size / 2);
    } else {
        int left = get_value(node->left, start, size/2, size / 2);
        int right = get_value(node->right, size/2, end, size / 2);
        return min(left, right);
    }
}

int main(){
    int N, num, M, xi, xj;
    cin >> N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        cin >> num;
        vec.push_back(num);
    }
    Node *root = make_tree(vec, 0, vec.size() - 1);
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> xi >> xj;
        int val = get_value(root, xi, xj, vec.size());
        cout << val;
    }
}