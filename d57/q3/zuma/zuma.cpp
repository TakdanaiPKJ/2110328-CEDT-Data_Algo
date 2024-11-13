#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to explode balls that are consecutive and have the same color (3 or more consecutive balls)
bool explode(vector<int>& balls) {
    bool exploded = false;
    int i = 0;
    
    while (i < balls.size()) {
        int count = 1;
        
        // Count consecutive balls of the same color
        while (i + 1 < balls.size() && balls[i] == balls[i + 1]) {
            count++;
            i++;
        }
        
        // If there are 3 or more consecutive balls, remove them
        if (count >= 3) {
            balls.erase(balls.begin() + i - count + 1, balls.begin() + i + 1);
            exploded = true;
            
            // Return immediately after explosion to allow re-checking of the changed list
            return exploded;
        }
        
        i++;
    }
    return exploded;
}

// Main game function
vector<int> zumaGame(int N, int K, int V, vector<int>& balls) {
    // Insert the new ball at the specified position
    balls.insert(balls.begin() + K, V);
    
    // Continuously check for explosions until no more explosions occur
    while (explode(balls)) {}
    
    return balls;
}

int main() {
    int N, K, V;
    cin >> N >> K >> V;
    
    vector<int> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i];
    }
    
    // Run the game logic and get the result after insertion and explosion
    vector<int> result = zumaGame(N, K, V, balls);
    
    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
