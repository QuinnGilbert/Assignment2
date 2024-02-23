#include <bits/stdc++.h>
#include <thread>
#include <atomic>

using namespace std;

int getNext() {
    return rand() % 10;
}

int main() {

    int N = 10; // number of guests

    std::atomic<bool> cupcake(false); 
    std::atomic<bool> stop(false);
    std::atomic<int> currentGuest(getNext()); // minotaur chooses first guess

    vector<std::thread> threads(N);

    // thread 1 is the counter
    threads[0] = std::thread([&]() {
        int count=0;
        while(!stop) {
            if(currentGuest == 0) {
                cout << 0 << endl;
                if(!cupcake) {
                    count++;
                    cupcake = true;
                }
                if(count==N-1) stop = true;
                currentGuest = getNext(); // warden chooses next guest
            }
        }
    });
    for(int i = 1; i<N; i++) {
        threads[i] = std::thread([&](int guest) {
            bool firstTime = true;
            while(!stop) {
                if(currentGuest == guest) {
                    cout << guest << endl;
                    if(firstTime && cupcake) {
                        cupcake = false;
                        firstTime = false;
                    }
                    currentGuest = getNext(); // warden chooses next guest
                }
            }
        }, i);
    }
    
    for(int i=0;i<N;i++) {
        threads[i].join();
    }

}