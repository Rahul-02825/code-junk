import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "./index.css";
import App from "./App.jsx";
import Path from "./path.jsx";
import Get from "./Get.jsx"
import { QueryClient, QueryClientProvider } from "@tanstack/react-query";
const queryClient = new QueryClient();


createRoot(document.getElementById("root")).render(
  <QueryClientProvider client={queryClient}>
    <Get />
  </QueryClientProvider>
);
