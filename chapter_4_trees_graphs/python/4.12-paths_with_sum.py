TreeNode = __import__('tree').TreeNode


def get_or_zero(ht, key):
    """
    Returns value at key or zero if it does not exist
    """
    return ht[key] if key in ht else 0


def modify_hash_table(ht, key, delta):
    """
    Modifies a key in a hash table
    """
    new_count = get_or_zero(ht, key) + delta
    if not new_count:
        del ht[key]
    else:
        ht[key] = new_count


def count_paths_with_sum(root, target_sum):
    """
    Returns the amount of paths in a binary tree that equal a target sum
    """
    return cpws_helper(root, 8, 0, {})


def cpws_helper(root, target_sum, running_sum, path_count):
    """
    Helper
    """
    if not root:
        return 0
    # Count paths with sum ending at the current node
    running_sum += root.value
    matching_sum = running_sum - target_sum
    total_paths = get_or_zero(path_count, matching_sum)
    # If running_sum equals target_sum, then one additional path starts at root.
    # Add in this path.
    if (running_sum == target_sum):
        total_paths += 1
    # Increment path_count, recurse, then decrement path_count
    modify_hash_table(path_count, running_sum, 1)  # Increment path_count
    total_paths += cpws_helper(root.left, target_sum, running_sum, path_count)
    total_paths += cpws_helper(root.right, target_sum, running_sum, path_count)
    modify_hash_table(path_count, running_sum, -1)  # Decrement pathCount
    return total_paths


n1 = TreeNode(10)
n2 = TreeNode(5)
n3 = TreeNode(-3)
n1.left = n2
n1.right = n3
n4 = TreeNode(3)
n5 = TreeNode(1)
n2.left = n4
n2.right = n5
n7 = TreeNode(11)
n3.right = n7
n8 = TreeNode(3)
n9 = TreeNode(-2)
n4.left = n8
n4.right = n9
n11 = TreeNode(2)
n5.right = n11

print(count_paths_with_sum(n1, 8))  # 3
