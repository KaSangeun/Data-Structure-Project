# Data-Structure-Project
**Duration**: 2022.10.10.04 ~ 2022.12.06 <br/>
Efficient route optimization for collecting river floating debris using Prim's Algorithm

## Problem Statement
하천 부유 쓰레기 데이터를 수집하는 과정에서, 쓰레기가 특정 지점에 밀집되는 경향이 있다는 것을 발견하였다. <br/>
During the process of collecting data on river-floating debris, we observed that waste tends to accumulate in specific locations. <br/><<br/>
특히, 사람들이 자주 다니는 하천의 징검다리 주변이나 하천과 육지가 맞닿는 지점에 쓰레기가 집중되는 현상이 뚜렷하게 나타났다. <br/>
Notably, trash was frequently found near stepping stones commonly used by pedestrians or along the contact points between riverbanks and the land. </br></br>
이러한 지점을 중심으로 쓰레기를 수거한다면, 짧은 시간 안에 높은 효율을 낼 수 있을 것이라고 생각했다. <br/>
We hypothesized that prioritizing waste collection in these high-density areas could significantly increase efficiency within a short time frame. <br/>

## Approach
서울시 내 4 개의 자원회수시설을 기준으로 각 자원회수시설별로 구역을 나누어 자원회수시설에서 시작하여 인근 하천의 징검다리와 그 주변을 모두 지나면서 쓰레기를 수거할 수 있는 가장 빠른 경로를 탐색하고자 한다. <br/>
Seoul was divided into four zones, each centered around one of the city’s four resource recovery facilities. In each zone, we aimed to find the most efficient route starting from the assigned facility and passing through nearby rivers—focusing on stepping stones and their surrounding areas—to collect floating debris more effectively. <br/>

각 자원회수시설별 하천은 아래 표와 같다. </br>
The following table shows the nearby rivers for each waste recovery facility. <br/>
| 구역<br/>(Zone)       | 자원회수시설<br/>(Resource Recovery Facility)       | 인근 하천<br/>(Nearby Rivers)                                                 |
|--------------------------------------|----------------------------------|----------------------------------------------------------------|
| 1 | 마포 자원회수시설</br>(Mapo Resource Recovery Facility) | 불광천(Bulgwangcheon), 홍제천(Hongjecheon), 구파발천(Gupabalcheon), 청계천(Cheonggyecheon) |
| 2 | 노원 자원회수시설</br>(Nowon Resource Recovery Facility) | 청계천(Cheonggyecheon), 성북천(Seongbukcheon), 정릉천(Jeongneungcheon), 목동천(Mokdongcheon), 중랑천(Jungnangcheon) |
| 3 | 양천 자원회수시설</br>(Yangcheon Resource Recovery Facility) | 안양천(Anyangcheon), 목감천(Mokgamcheon), 도림천(Dorimcheon), 반포천(Banpocheon) |
| 4 | 강남 자원회수시설</br>(Gangnam Resource Recovery Facility) | 반포천(Banpocheon), 양재천(Yangjaecheon), 탄천(Tancheon), 세곡천(Segokcheon), 중랑천(Jungnangcheon) |


## Solution 
[Conditions] 
- 거리(가중치)를 기준으로 빠른 경로를 탐색할 것 (The goal is to find the fastest route based on distance (used as edge weight).)
- 모든 지점을 한 번씩 다 거칠 것 (All target locations must be visited exactly once.)
- 시작 지점은 자원회수시설로 고정될 것 (The route has to begin at the designated resource recovery facility.) <br/>

👉 위 조건을 만족시키는 자료구조는 **최소 비용 신장 트리**이다! (To satisfy these conditions, a **Minimum Spanning Tree (MST)** was used.) <br/>
그래프 내 간선이 많을 것으로 예상되기 때문에 **프림 알고리즘**을 활용하였다. (Since the graph is expected to contain many edges, **Prim’s algorithm** was applied.) <br/>

### Weights
여기서 가중치는 거리(km)를 나타내므로, 위에서 정리한 엑셀 파일의 위도와 경도를 통해 가중치를 구하였다. <br/>
Edge weights(distances) were calculated using latitude and longitude values from the dataset. <br/>

마침 위도와 경도를 통해 거리를 구하는 [웹사이트](https://boulter.com/gps/distance/?from=37.463782%09127.090359&to=37.490861%09127.068267&units=k)가 있어서 이 사이트를 활용하였다. <br/>
We use this [website](https://boulter.com/gps/distance/?from=37.463782%09127.090359&to=37.490861%09127.068267&units=k) to compute distances between coordinates. <br/>

### Code 
앞에서 구한 가중치를 바탕으로 각 구역별로 현재 노드, 이웃 노드, 가중치(거리) 순서으로 txt 파일을 만들어 준다. <br/>
Based on the calculated weights, we created a .txt file for each zone containing the current node, neighboring node, and weight(distance) in order. <br/><br/>
거리는 정수로 나타내기 위해 100을 곱한 값으로 표기하였다. <br/>
To represent the distances as integers, each value was multiplied by 100. <br/><br/>

프림 알고리즘을 포함한 코드는 [이곳]()에서 확인할 수 있다. <br/>
The full code, including Prim’s algorithm, can be found [here](웹사이트). <br/>

## Results

