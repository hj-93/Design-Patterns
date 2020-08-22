#include <iostream>
#include <cstdlib>
#include <vector>

template <typename NeuronType>
class GenericNeuronBase
{
  public:
  template <typename T>
  void connect_to(T& other)
  {
    for (typename NeuronType::value_type& from: *static_cast<NeuronType*>(this))
    {
      for (typename NeuronType::value_type& to: other)
      {
        from.out.push_back(&to);
        to.in.push_back(&from);
      }
    }
  }
};
class Neuron : public GenericNeuronBase<Neuron>
{
  public:
    using value_type = Neuron;
    Neuron()
    {
      static int id = 1;
      m_id = id++;
    }
    Neuron* begin() {std::cout << "custom begin\n"; return this;}
    Neuron* end()   {return this+1;}
    std::vector<Neuron*> in, out;
  private:
    int m_id;
};

class NeuronCluster : public std::vector<Neuron>, public GenericNeuronBase<NeuronCluster>
{
  public:
    using value_type = Neuron;
    NeuronCluster(int i)
    {
      while(i--)
      {
        emplace_back(Neuron{});
      }
    }
};

int main()
{
    Neuron neuron1, neuron2;
    NeuronCluster neuronCluster1(2);
    NeuronCluster neuronCluster2(2);
    
    neuron1.connect_to(neuronCluster1);
    neuronCluster1.connect_to(neuronCluster2);
    neuronCluster2.connect_to(neuron2);
    neuron2.connect_to(neuron1);
}
