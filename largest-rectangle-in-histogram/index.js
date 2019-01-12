function assert(a, b) {
  if (a !== b) {
    throw new Error(`expected ${b} but received ${a}`);
  }
}

function findLargestRectangle(histogram) {
  // Array<{index: number, height: number}>
  const rectangles = [];
  let maximum = -1;

  function getTopStack() {
    return rectangles.length > 0 ? rectangles[rectangles.length - 1] : null;
  }

  function popValue(currentPos) {
    const { height, index } = rectangles.pop();
    const currentSize = height * (currentPos - index);
    maximum = Math.max(maximum, currentSize);
    return index;
  }

  for (let index = 0; index < histogram.length; ++index) {
    let topStackRectangle = getTopStack();

    const currentHeight = histogram[index];

    if (!topStackRectangle || currentHeight > topStackRectangle.height) {
      rectangles.push({ index, height: currentHeight });
    } else if (currentHeight < topStackRectangle.height) {
      let lastIndex;
      while (rectangles.length > 0 && currentHeight < getTopStack().height) {
        lastIndex = popValue(index, currentHeight);
      }
      rectangles.push({ height: currentHeight, index: lastIndex });
    }
  }

  while (rectangles.length > 0) {
    popValue(histogram.length);
  }

  return maximum;
}

assert(findLargestRectangle([0, 1, 2, 3, 4, 4, 2]), 10);
assert(findLargestRectangle([1, 2, 2, 1, 4, 1]), 6);

console.log("\n✅  test passing");
