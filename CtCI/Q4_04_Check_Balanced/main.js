function isBalanced(tree) {
  return getHeight(tree).isBalanced;
}

function getHeight(tree) {
  if (tree === null || tree === undefined) {
    return { height: 0, isBalanced: true };
  }

  let rightInfo = getHeight(tree.right);
  let leftInfo = getHeight(tree.left);

  return {
    height: Math.max(rightInfo.height, leftInfo.height) + 1,
    isBalanced:
      rightInfo.isBalanced &&
      leftInfo.isBalanced &&
      Math.abs(rightInfo.height - leftInfo.height) <= 1,
  };
}

console.log(isBalanced({ left: { left: {}, right: {} }, right: { left: {} } }));
