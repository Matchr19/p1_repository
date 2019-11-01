#include <vector>
#include <iostream>
using namespace std;
void swap(vector<int>& v, int x, int y);

void quicksort(vector<int> &vec, int L, int R) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];
    cout << "Pivot er: " << vec[mid] << ", på plads " << mid+1 << endl;

    while (i<R || j>L) {
        while (vec[i] < piv)
        {
            cout << vec[i] << ", " << i+1 << " er mindre end " << piv << endl;
            i++;
        }
        while (vec[j] > piv)
        {
            cout << vec[j] << ", " << j+1 << " er større end " << piv << endl;
            j--;
        }
        if (i <= j) {
            cout << vec[i] << ", " << i+1 << " er større eller lig " << vec[j] << ", " << j+1 << endl;
            swap(vec, i, j); 
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

void swap(vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

    cout << "Bytter " << x+1 << " & " << y+1 << ", som er " << v[y] << " & " << v[x] << endl;
}

int main() {
    srand(time(NULL));
    int randtal {};
    int high {};
    std::cout << "Antal tal i vektoren? "; std::cin >> randtal;
    std::cout << "\nHøjest mulige tal? "; std::cin >> high; 
    vector<int> vec1(randtal);

    for(int i = 0; i<vec1.size(); i++)
    {
        int nummer {};
        nummer = rand() % high;
        vec1[i] = nummer;

    }


    for(int i = 0; i<vec1.size(); i++)
    {
        std::cout  << vec1[i] << ", ";
    }
    std::cout << std::endl << std::endl;
    quicksort(vec1, 0, randtal - 1);

    for(int i = 0; i<vec1.size(); i++)
    {
        std::cout  << vec1[i] << ", ";
    }
    std::cout << std::endl << std::endl;

}