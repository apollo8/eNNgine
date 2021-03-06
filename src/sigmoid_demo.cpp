
#include "SigmoidNeuron.hpp"
#include "demos.hpp"

/* The following function searches for the best bias and weight values
 * for implementing a NOT gate based on a single sigmoid neuron.
 *
 * The answer is -5 for the bias and -10 for the weight.
 *
 * {0} --( -10 )--> [ -5 ] --> {0.993307}
 * {1} --( -10 )--> [ -5 ] --> {0.00669285}
 *
 */
void search_for_not_gate_demo()
{
    float difference = -2;
    float best_bias;
    float best_weight;

    for (float bias = -10; bias < 10; bias = bias + 0.1) {
        for (float weight = -10; weight < 10; weight = weight + 0.1) {
            SigmoidNeuron p_NOT(bias, {weight});

            /* this should be close to 1 */
            float output_zero = p_NOT.compute({0});
            /* this should be close to 0 */
            float output_one = p_NOT.compute({1});

            /* the difference needs to be maximized */
            float current_difference = output_zero - output_one;

            if (current_difference > difference) {
                difference = current_difference;
                best_bias = bias;
                best_weight = weight;
            }
        }
    }

    std::cout << "difference: " << difference << std::endl;
    std::cout << "bias: " << best_bias << std::endl;
    std::cout << "weight: " << best_weight << std::endl;
}

void run_sigmoid_neuron_demo()
{
    /* sigmoid neuron implementing OR gate */

    std::cout << "OR gate" << std::endl;
    SigmoidNeuron p_OR(-5, {10, 10});

    std::cout << "{0, 0} -> " << p_OR.compute({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << p_OR.compute({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << p_OR.compute({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << p_OR.compute({1, 1}) << std::endl;

    /* sigmoid neuron implementing NOT gate */

    std::cout << std::endl << "NOT gate" << std::endl;
    SigmoidNeuron p_NOT(5, {-10});

    std::cout << "{0} -> " << p_NOT.compute({0}) << std::endl;
    std::cout << "{1} -> " << p_NOT.compute({1}) << std::endl;

    /* multilayer network implementing IMPLIES function */

    std::cout << std::endl << "IMPLIES function" << std::endl;

    auto implies = [&](float a, float b) {
        // IMPLIES(a, b) == OR(NOT(a), b)
        return p_OR.compute({p_NOT.compute({a}), b});
    };

    std::cout << "0 -> 0 ? " << implies(0, 0) << std::endl;
    std::cout << "0 -> 1 ? " << implies(0, 1) << std::endl;
    std::cout << "1 -> 0 ? " << implies(1, 0) << std::endl;
    std::cout << "1 -> 1 ? " << implies(1, 1) << std::endl;
}

