#include <bits/stdc++.h>
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string,vector<string>> flightGraph;
        vector<string> travelItinerary;
        for (int i = 0; i < tickets.size(); i++) {
            string fromAirport = tickets[i][0];
            string toAirport = tickets[i][1];

            flightGraph[fromAirport].push_back(toAirport);
        }
        
        // Sort destinations in reverse order to visit lexical smaller destinations first
        for (auto &entry : flightGraph) {
            sort(entry.second.rbegin(), entry.second.rend());
        }

        stack<string> dfsStack;
        dfsStack.push("JFK");

        while (!dfsStack.empty()) {
            // Get the current airport from the top of the stack
            string currentAirport = dfsStack.top();

            vector<string> &destinations = flightGraph[currentAirport];

            if (!destinations.empty()) {
                // Choose the next destination (the one in lexicographically larger order)
                string nextDestination = destinations.back();
                destinations.pop_back();

                dfsStack.push(nextDestination);
            } else {
                // If there are no more destinations from the current airport, add it to the itinerary
                travelItinerary.push_back(currentAirport);
        
                dfsStack.pop();
            }
        }
        
        // Reverse the itinerary to get the correct order
        reverse(travelItinerary.begin(), travelItinerary.end());
        return travelItinerary;



    }
};