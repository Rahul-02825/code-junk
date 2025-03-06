import {useQuery} from "@tanstack/react-query"
import {useState} from "react"
import axios from "axios"

// function for tanstack query
const fetchData = async() =>{
    const response = await axios.get("http://api.weatherapi.com/v1/current.json?key=a2b2937d86794e44946163638250503&q=Madurai&aqi=no")
    console.log(response)
    return response.data
}
const GetData = () =>{
    const {data,error,isLoading} = useQuery({
        queryKey : ['weatherData'],
        queryFn : fetchData,  
    })
    console.log("data",data)
    if (isLoading) return <p>Loading...</p>;
    if (error) return <p>Error: {error.message}</p>;
    return(
        <div>
            <div>Weather of london</div>
            <div>{data.current.condition.text}</div>
            {/* {Array.isArray(data) && data.map((items)=>(
                <div key={items.id}>
                    <div>{items.current.cloud}</div>
                </div>
            ))} */}
        </div>
    )
}   
export default GetData