import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import Home from "./App";

const Path = () => {
    <Router>
      <Routes>
        <Route path="/" element={<Home/>}></Route>
      </Routes>
    </Router>
};

export default Path
