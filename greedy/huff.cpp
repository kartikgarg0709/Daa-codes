#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

class nodes{
public:
    nodes *left;
    nodes *right;
    pair<char,int> a;
};

class comp1 {
public:
    bool operator()(const nodes* a, const nodes* b) {
        return a->a.second > b->a.second;
    }
};

bool comp(const pair<char,int>& huff1, const pair<char,int>& huff2){
    return huff1.second < huff2.second;
}

void printCodes(nodes* root, string code) {
    if (root == nullptr)
        return;

    if (root->a.first != '&')
        cout << root->a.first << ": " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void generatecode(vector<pair<char,int>> huff){
    sort(huff.begin(), huff.end(), comp);
    
    priority_queue<nodes*, vector<nodes*>, comp1> p1;
    
    // Create nodes for each symbol and its frequency and push them into the priority queue
    for(int i = 0; i < huff.size(); i++){
        nodes* newNode = new nodes();
        newNode->a = huff[i];
        newNode->left = nullptr;
        newNode->right = nullptr;
        p1.push(newNode);
    }

    // Construct the Huffman tree
    while(p1.size() > 1){
        nodes* left = p1.top();
        p1.pop();
        nodes* right = p1.top();
        p1.pop();

        // Create a new node with the sum of frequencies of left and right children
        nodes* newNode = new nodes();
        newNode->a = {'&', left->a.second + right->a.second};
        newNode->left = left;
        newNode->right = right;

        // Push the new node back to the priority queue
        p1.push(newNode);
    }

    // At this point, the root of the Huffman tree is the only node left in the priority queue
    nodes* root = p1.top();

    // Print the Huffman codes
    cout << "Huffman Codes:" << endl;
    printCodes(root, "");
}

int main(){
    vector<pair<char,int>> huff = {{'a',45},{'b',13},{'c',12},{'d',16},{'e',9},{'f',5}};
    generatecode(huff);
    return 0;
}
