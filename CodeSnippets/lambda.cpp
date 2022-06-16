/*
 * Lambda function definition and its assignment
 * auto lambda_function = [???](parameters) -> return_type { doing something to
 * return...};
 * use this function as typical functions: return_type ret = lambda_function(parameters);
 * Capture by reference: Capture the variable that encloses this lambda
 * function.
 * Ex) int x; ... auto lambda_function = [&x](parameters) -> return_type { doing
 * something to return}; By doing this, we can modify x inside the function.
 * We can give lambda function as argument in stl algorithm.
 * When the lambda function is going to be given as comparator, like to
 * priority_queue,
 * do this: priority_queue<type, vector<type>, decltype<lambda_function>>
 * pq(lambda_function).
 */
