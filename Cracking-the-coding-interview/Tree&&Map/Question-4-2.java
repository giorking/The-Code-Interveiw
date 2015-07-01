/**
 * Created by lawrence on 6/28/15.
 */
/**
 * Definition for Directed graph.
 */

import java.util.*;

class DirectedGraphNode {
    int label;
    ArrayList<DirectedGraphNode> neighbors;
    DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
};


public class Solution {
    public boolean connectedSet2(DirectedGraphNode start, DirectedGraphNode end) {
        // Write your code here
        Set set = new HashSet();
        set.add(start);
        LinkedList<DirectedGraphNode> q = new LinkedList<DirectedGraphNode>();
        q.offer(start);
        DirectedGraphNode cur;
        while (!q.isEmpty()) {
            cur = q.poll();
            if (cur == end) return true;
            for (int i = 0; i < cur.neighbors.size(); i ++) {
                if (!set.contains(cur.neighbors.get(i))) {
                    set.add(cur.neighbors.get(i));
                    q.offer(cur.neighbors.get(i));
                }
            }
        }
        return false;
    }
}
