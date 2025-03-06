import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import { QueryClient, QueryClientProvider } from "@tanstack/react-query";

import Home from "./App";
import Get from "./Get"
import PostArray from "./PostArray"
const queryClient = new QueryClient(); // Create a single QueryClient instance

const Path = () => {
    return(
     
            <Router>
                <Routes>
                    <Route path="/" element={<Home />}></Route>
                    <Route path="/Get" element={<Get />}></Route>
                    <Route path="/PostArray" element={<PostArray />}></Route>
                </Routes>
            </Router>
    )
};
export default Path;


