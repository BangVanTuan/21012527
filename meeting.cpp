#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct Interval để lưu trữ thông tin về cuộc họp
struct Interval {
    int start;
    int end;
};

// Hàm so sánh để sắp xếp các cuộc họp theo thứ tự tăng dần thời gian bắt đầu
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

// Hàm để tìm các khoảng thời gian chung trong vector các cuộc họp
void findMeetingTimes(const vector<Interval>& meetings) {
    vector<Interval> mergedMeetings;

    // Sắp xếp các cuộc họp theo thứ tự tăng dần thời gian bắt đầu
    vector<Interval> sortedMeetings = meetings;
    sort(sortedMeetings.begin(), sortedMeetings.end(), compareIntervals);

    // Duyệt qua các cuộc họp đã sắp xếp
    for (const Interval& meeting : sortedMeetings) {
        // Nếu danh sách cuộc họp rỗng hoặc cuộc họp hiện tại không giao với cuộc họp trước đó trong danh sách
        if (mergedMeetings.empty() || meeting.start > mergedMeetings.back().end) {
            mergedMeetings.push_back(meeting);
        }
        // Nếu cuộc họp hiện tại giao với cuộc họp trước đó trong danh sách
        else {
            mergedMeetings.back().end = max(mergedMeetings.back().end, meeting.end);
        }
    }

    // In ra các khoảng thời gian chung
    for (const Interval& meeting : mergedMeetings) {
        cout << "[" << meeting.start << ", " << meeting.end << "] ";
    }
    cout << endl;
}

int main() {
    vector<int> start = {1, 3, 0, 8, 8};
    vector<int> end = {5, 4, 3, 10, 9};

    // Tạo vector lưu trữ các cuộc họp dưới dạng Interval
    vector<Interval> meetings;
    for (int i = 0; i < start.size(); i++) {
        Interval meeting;
        meeting.start = start[i];
        meeting.end = end[i];
        meetings.push_back(meeting);
    }

    // Tìm các khoảng thời gian chung trong các cuộc họp
    findMeetingTimes(meetings);

    return 0;
}
