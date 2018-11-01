#include<algorithm>
#include<list>
#include<vector>

using namespace std;

class ExamRoom {
public:
	vector<int> room;
	int N;

	ExamRoom(int N) {
		this->N = N;
	}

	int seat() {
		if (room.empty()){
			room.push_back(0);
			return 0;
		}
		int dist = max(room[0], N - 1 - room[room.size() - 1]);
		for (int i = 0; i < room.size() - 1; i++){
			dist = max(dist, (room[i + 1] - room[i]) / 2);
		}
		if (room[0] == dist){
			room.insert(room.begin(), 0);
			return 0;
		}
		for (int i = 0; i < room.size() - 1; i++){
			if (dist == (room[i + 1] - room[i]) / 2){
				room.insert(room.begin() + i + 1, (room[i + 1] + room[i]) / 2);
				return room[i + 1];
			}
		}
		room.push_back(N - 1);
		return N - 1;
	}

	void leave(int p) {
		for (int i = 0; i < room.size(); i++){
			if (room[i] == p)
				room.erase(room.begin() + i);
		}
	}
};

/**
* Your ExamRoom object will be instantiated and called as such:
* ExamRoom obj = new ExamRoom(N);
* int param_1 = obj.seat();
* obj.leave(p);
*/