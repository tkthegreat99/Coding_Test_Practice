#include <iostream>

using namespace std;

int w, h, n, m;

int main() {
    
    cin >> w >> h >> n >> m;

    int height = 1 + n;
    int width = 1 + m;
    
    int row = w % height == 0 ? w / height : w / height + 1;
    int col = h % width == 0 ?  h / width : h / width + 1;
    
    cout << row * col << '\n';

    return 0;
}