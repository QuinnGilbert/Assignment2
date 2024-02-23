#include <bits/stdc++.h>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

using namespace std;



int main() {

    int N = 10; // number of guests
    mutex mtx;
    condition_variable cv;
    deque<int> queue;

    thread guests[N];

    for(int i=0;i<N;i++) {
        guests[i] = thread([&](int guest) {

            mtx.lock();
            queue.push_back(guest); // guest initially enters
            this_thread::sleep_for(chrono::seconds(1)); // wait for push to succeed
            mtx.unlock();

            while(true) {

                if(queue.front() == guest) {
                    // guest at the front of the line enters
                    mtx.lock();

                    cout<<"Queue: ";
                    for(int i:queue) cout<<i<<" ";
                    cout<<endl;

                    queue.pop_front();
                    cout << guest << " Enters" << endl;
                    this_thread::sleep_for(chrono::seconds(rand() % 5 + 1)); // stay in the room for a random amount of time
                    cout << guest << " Exits" << endl;
                    queue.push_back(guest);
                    mtx.unlock();
                }

            }

        }, i );
    }

    for(int i=0;i<N;i++) {
        guests[i].join();
    }

}