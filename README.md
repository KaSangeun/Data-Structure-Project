# Data-Structure-Project
**Duration**: 2022.10.10.04 ~ 2022.12.06 </br>
Efficient route optimization for collecting river floating debris using Prim's Algorithm

## Problem Statement
하천 부유 쓰레기 데이터를 수집하는 과정에서, 쓰레기가 특정 지점에 밀집되는 경향이 있다는 것을 발견하였다. </br>
During the process of collecting data on river-floating debris, we observed that waste tends to accumulate in specific locations. </br></br>
특히, 사람들이 자주 다니는 하천의 징검다리 주변이나 하천과 육지가 맞닿는 지점에 쓰레기가 집중되는 현상이 뚜렷하게 나타났다. </br>
Notably, trash was frequently found near stepping stones commonly used by pedestrians or along the contact points between riverbanks and the land. </br></br>
이러한 지점을 중심으로 쓰레기를 수거한다면, 짧은 시간 안에 높은 효율을 낼 수 있을 것이라고 생각했다. </br>
We hypothesized that prioritizing waste collection in these high-density areas could significantly increase efficiency within a short time frame. </br>

## Approach
서울시 내 4 개의 자원회수시설을 기준으로 각 자원회수시설별로 구역을 나누어 자원회수시설에서 시작하여 인근 하천의 징검다리와 그 주변을 모두 지나면서 쓰레기를 수거할 수 있는 가장 빠른 경로를 탐색하고자 한다. </br>
Seoul was divided into four zones, each centered around one of the city’s four resource recovery facilities. In each zone, we aimed to find the most efficient route starting from the assigned facility and passing through nearby rivers—focusing on stepping stones and their surrounding areas—to collect floating debris more effectively. </br>

각 자원회수시설별 하천은 아래 표와 같다. </br>
The following table shows the nearby rivers for each waste recovery facility. </br>
| Resource Recovery Facility       | Nearby Rivers                                                 |
|----------------------------------|----------------------------------------------------------------|
| Mapo Resource Recovery Facility | Bulgwangcheon, Hongjecheon, Gupabalcheon, Cheonggyecheon |
| Nowon Resource Recovery Facility | Cheonggyecheon, Seongbukcheon, Jeongneungcheon, Mokdongcheon, Jungnangcheon |
| Yangcheon Resource Recovery Facility | Anyangcheon, Mokgamcheon, Dorimcheon, Banpocheon |
| Gangnam Resource Recovery Facility | Banpocheon, Yangjaecheon, Tancheon, Segokcheon, Jungnangcheon |

## Dataset


## Solution 
