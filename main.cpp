
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <sstream>
#include <iostream>

// 共有データ
std::vector<std::vector<int>> mapData;
std::mutex mutex;
std::condition_variable condition;
bool dataReady = false;

// CSV読み込み関数（バックグラウンドで実行）
void loadCSV(const std::string& filename) {
    std::vector<std::vector<int>> tempData;

    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<int> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));
        }
        tempData.push_back(row);
    }

    {
        std::lock_guard<std::mutex> lock(mutex);
        mapData = std::move(tempData);
        dataReady = true;
    }
    condition.notify_one();
}

int main() {
    // CSV読み込みスレッド開始
    std::thread loader(loadCSV, "map.csv");

    // メインスレッド：データ準備完了まで待つ
    {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, []() { return dataReady; });
    }

    // ここで mapData を使ってマップチップを描画する処理を実装
    std::cout << "CSVデータの読み込み完了。行数: " << mapData.size() << std::endl;

    // mapDataの中身を表示
    for (const auto& row : mapData) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    loader.join();
    return 0;
}
