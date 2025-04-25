Algorithm BubbleSort(arr, n)
// Sorts array arr of size n using Bubble Sort
{
    for i:= 0 to n - 2 do
        for j:= 0 to n - i - 2 do
            if (arr[j] > arr[j + 1]) then
                Swap arr[j] and arr[j + 1];
}

Algorithm Partition(arr, low, high)
// Partitions arr and returns the pivot index
{
    pivot:= arr[high];
    i:= low - 1;
    for j:= low to high - 1 do
        if (arr[j] < pivot) then
        {
            i:= i + 1;
            Swap arr[i] and arr[j];
        }
    Swap arr[i + 1] and arr[high];
    return i + 1;
}      


Algorithm QuickSort(arr, low, high)
// Sorts array arr using Quick Sort recursively
{
    if (low < high) then
    {
        pivotIndex:= Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

Algorithm MeasureExecutionTime(AlgorithmName)
// Measures and displays the execution time of a given algorithm
{
    StartTime:= CurrentTime();
    Run AlgorithmName;
    EndTime:= CurrentTime();
    ExecutionTime:= EndTime - StartTime;
    Print "Execution time of", AlgorithmName, "is", ExecutionTime;
}
