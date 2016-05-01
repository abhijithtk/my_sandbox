/**
 * This is the interface that represents nested lists.
 * You should not implement it, or speculate about its implementation.
 */
public interface NestedInteger
{
    /** @return true if this NestedInteger holds a single integer, rather than a nested list */
    boolean isInteger();
 
    /** @return the single integer that this NestedInteger holds, if it holds a single integer
     * Return null if this NestedInteger holds a nested list */
    Integer getInteger();
 
    /** @return the nested list that this NestedInteger holds, if it holds a nested list
     * Return null if this NestedInteger holds a single integer */
    List<NestedInteger> getList();
}



1.
 /**
 * Given a nested list of integers, returns the sum of all integers in the list weighted by their depth
 * For example, given the list {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2, one 2 at depth 1)
 * Given the list {1,{4,{6}}} the function should return 27 (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3)
 */

public int depthSumHelper (List<NestedInteger> input, int depth) {     
    List<NesterInteger>::iterator lit;
    int sum = 0;
    for(lit = input.begin(); lit != input.end(); lit++) {
        if(lit->isInteger()) {
            sum += depth * lit->getInteger();
        }
        else {
            sum += depthSumHelper(lit->getList(), depth + 1 );
        }
    }
    return sum;
}

public int depthSum (List<NestedInteger> input) { 
    return depthSumHelper(input,1);
}

2. 
/**
 * Given a nested list of integers, returns the sum of all integers in the list weighted by their reversed depth.
 * For example, given the list {{1,1, ,{4,5}},2,{1,1}} the deepest level is 2. Thus the function should return 8 (four 1's with weight 1, one 2 with weight 2)
 * 2 * 2 + (1*1 + 1*1 + 1*1+ 1*1) = 8
 * Given the list {1,{4,{6}}} the function should return 17 (one 1 with weight 3, one 4 with weight 2, and one 6 with weight 1)
 */

int findMaxDepth(List<NestedInteger> input, int depth) {
    List<NesterInteger>::iterator lit;
    int max_depth = depth;
    for(lit = input.begin(); lit != input.end(); lit++) {
        if(!lit->isInteger()) {
            int tmp = findMaxDepth(lit->getList(), depth + 1);
            if(tmp > max_depth)
                max_depth = tmp;
        }
    }
    return max_depth;
}    
    
public int reverseDepthSumHelper (List<NestedInteger> input, int max_depth) { 
    List<NesterInteger>::iterator lit;
    int sum = 0;
    if(max_depth == 0)
        return 0;
    for(lit = input.begin(); lit != input.end(); lit++) {
        if(lit->isInteger()) {
            sum += max_depth * lit->getInteger();
        }
        else {
            sum += depthSumHelper(lit->getList(), max_depth - 1 );
        }
    }
    return sum;
}
    
public int reverseDepthSum (List<NestedInteger> input) { 
    int max_depth = findMaxDepth(input, 1);
    return reverseDepthSumHelper(input, max_depth);
}
