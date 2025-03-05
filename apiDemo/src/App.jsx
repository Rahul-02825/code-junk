import { useQuery } from "@tanstack/react-query";
import { useMutation } from "@tanstack/react-query";
import {useState} from "react"
import axios from "axios";
import React from "react";

const fetchLoveStatus = async ({firstname,secondname}) => {

  const options = {
    method: 'GET',
    url: `https://flames-love-calculator.p.rapidapi.com/flame/${firstname}/${secondname}`,
    headers: {
      'x-rapidapi-key': '9120e0975amsh64c385c26183c46p19cfedjsnf82b98f4c934',
      'x-rapidapi-host': 'flames-love-calculator.p.rapidapi.com'
    }
  };  

  const response = await axios.request(options);
  console.log(response.data);
  return response.data; // Adjust based on actual API response  
};

const LoveComponent = () => {
  const initialFormData = {
    firstname:"",
    secondname:""
  }
  const [formData,setFormData] = useState(initialFormData)
  // const { data, error, isLoading } = useQuery({
  //   queryKey: ["movies"],
  //   queryFn: fetchMovies,
  // });
  const mutation = useMutation({
    mutationFn:fetchLoveStatus,
    onSuccess:(data)=>{
      console.log(data)
    },
    onError:(error)=>{
      console.error(error)
    }
  })
  const handleSubmit = (e) =>{
    e.preventDefault()
    mutation.mutate(formData)
  }
  console.log(mutation.data);
  return (
    <div>
      <form onSubmit={handleSubmit}>
        <input type="text" value={formData.firstname}
        placeholder="fistname"
        onChange={(e)=>setFormData({...formData,firstname:e.target.value})}
        />
        <input type="text" value={formData.secondname}
        placeholder="seocndname"
        onChange={(e)=>setFormData({...formData,secondname:e.target.value})}
        />
        <button type="submit" className="btn btn-primary w-full">Submit</button>
      </form>
      <div>
        {/* {isLoading && <span className="loading loading-dots loading-xs"></span>}
        {error && <p className="text-red-500">Error: {error.message}</p>} */}

        {/* {Array.isArray(data) && data.length > 0
          ? data.map((item) => (
              <div key={item.id || item.name}>
                <div>{item.fullName || item.name}</div>
              </div>
            ))
          : !isLoading && <p>No data found.</p>} */}
      </div>
    </div>
  );
};

export default LoveComponent;
