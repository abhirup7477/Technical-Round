import java.util.*;
import java.io.*;

class Link {
    int node, weight;

    Link(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int totalLines = Integer.parseInt(reader.readLine().trim());
        List<String> inputs = new ArrayList<>();

        for (int i = 0; i <= totalLines; i++) {
            inputs.add(reader.readLine().trim());
        }

        String[] endpoints = inputs.get(inputs.size() - 1).split(" ");
        int startNode = Integer.parseInt(endpoints[0]);
        int goalNode = Integer.parseInt(endpoints[1]);

        List<String> relationData = inputs.subList(0, inputs.size() - 1);

        List<List<int[]>> grove = new ArrayList<>();
        List<int[]> activeTree = new ArrayList<>();

        for (String line : relationData) {
            if (line.equals("break")) {
                if (!activeTree.isEmpty()) {
                    grove.add(new ArrayList<>(activeTree));
                    activeTree.clear();
                }
            } else if (!line.isEmpty()) {
                String[] parts = line.split(" ");
                int[] values = new int[parts.length];
                for (int i = 0; i < parts.length; i++) {
                    values[i] = Integer.parseInt(parts[i]);
                }
                activeTree.add(values);
            }
        }
        if (!activeTree.isEmpty()) grove.add(activeTree);

        Map<String, Integer> spotIndex = new HashMap<>();
        int indexCount = 0;

        List<Set<Integer>> treeSpots = new ArrayList<>();
        for (List<int[]> cluster : grove) {
            Set<Integer> temp = new HashSet<>();
            for (int[] link : cluster) {
                temp.add(link[0]);
                for (int j = 1; j < link.length; j++) {
                    temp.add(link[j]);
                }
            }
            treeSpots.add(temp);
        }

        for (int t = 0; t < treeSpots.size(); t++) {
            for (int val : treeSpots.get(t)) {
                spotIndex.put(val + "_" + t, indexCount++);
            }
        }

        List<List<Link>> network = new ArrayList<>();
        for (int i = 0; i < indexCount; i++) network.add(new ArrayList<>());

        for (int tid = 0; tid < grove.size(); tid++) {
            for (int[] branch : grove.get(tid)) {
                int lower = branch[0];
                for (int k = 1; k < branch.length; k++) {
                    int upper = branch[k];
                    int lowId = spotIndex.get(lower + "_" + tid);
                    int upId = spotIndex.get(upper + "_" + tid);
                    network.get(lowId).add(new Link(upId, 1)); 
                    network.get(upId).add(new Link(lowId, 0)); 
                }
            }
        }

        Map<Integer, List<Integer>> sharedMap = new HashMap<>();
        for (String combo : spotIndex.keySet()) {
            String[] arr = combo.split("_");
            int node = Integer.parseInt(arr[0]);
            int id = spotIndex.get(combo);
            sharedMap.computeIfAbsent(node, k -> new ArrayList<>()).add(id);
        }

        for (List<Integer> ids : sharedMap.values()) {
            if (ids.size() > 1) {
                for (int i = 0; i < ids.size(); i++) {
                    for (int j = i + 1; j < ids.size(); j++) {
                        int a = ids.get(i), b = ids.get(j);
                        network.get(a).add(new Link(b, 1)); 
                        network.get(b).add(new Link(a, 1));
                    }
                }
            }
        }

        int begin = -1;
        List<Integer> possibleEnds = new ArrayList<>();

        for (int tid = 0; tid < grove.size(); tid++) {
            if (spotIndex.containsKey(startNode + "_" + tid)) {
                begin = spotIndex.get(startNode + "_" + tid);
            }
            if (spotIndex.containsKey(goalNode + "_" + tid)) {
                possibleEnds.add(spotIndex.get(goalNode + "_" + tid));
            }
        }

        if (begin == -1 || possibleEnds.isEmpty()) {
            System.out.println(-1);
            return;
        }

        int[] minEnergy = new int[indexCount];
        Arrays.fill(minEnergy, Integer.MAX_VALUE);

        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(begin);
        minEnergy[begin] = 0;

        while (!dq.isEmpty()) {
            int current = dq.pollFirst();
            for (Link edge : network.get(current)) {
                int newCost = minEnergy[current] + edge.weight;
                if (newCost < minEnergy[edge.node]) {
                    minEnergy[edge.node] = newCost;
                    if (edge.weight == 0){
                        dq.addFirst(edge.node);
                    }  
                    else{
                        dq.addLast(edge.node);
                    }
                }
            }
        }

        int result = Integer.MAX_VALUE;
        for (int d : possibleEnds){
            result = Math.min(result, minEnergy[d]);
        }

        if(result == Integer.MAX_VALUE){
            System.out.print(result);
        }
        else{
            System.out.print(-1);
        }
    }
}
